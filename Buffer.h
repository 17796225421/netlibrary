#pragma once

#include <vector>
#include <string>
#include <algorithm>

class Buffer
{
public:
    static const size_t kCheapPrepend = 8;
    static const size_t kInitalSize = 1024;

    explicit Buffer(size_t initialSize = kInitalSize)
        : buffer_(kCheapPrepend + initialSize),
          readerIndex_(kCheapPrepend),
          writerIndex_(kCheapPrepend)
    {
    }

    size_t readableBytes() const
    {
        return writerIndex_ - readerIndex_;
    }

    size_t writableBytes() const
    {
        return buffer_.size() - writerIndex_;
    }

    size_t prependableBytes()const{
        return readerIndex_;
    }

    void ensureWriteableByte(size_t len)
    {
        if (writableBytes() < len)
        {
            makeSpace(len); // 扩容
        }
    }

    // 把[data,data+len]内存上的数据，添加到writable缓冲区当中
    void append(const char *data,size_t len){
        ensureWriteableByte(len);
        std::copy(data,data+len,beginWrite());
        writerIndex_+=len;
    }

    char *beginWrite(){
        return begin()+writerIndex_;
    }

    const char *beginWrite()const{
        return begin()+writerIndex_;
    }

    // 从fd上读取数据
    ssize_t readFd(int fd,int *saveErrno);

private:
    char *begin()
    {
        return &*buffer_.begin(); // 迭代器转化为指针
    }

    const char *begin() const
    {
        return &*buffer_.begin();
    }

    // 返回缓冲区中可读数据的起始地址
    const char *peek() const
    {
        return begin() + readerIndex_;
    }

    // onMessage string <- Buffer
    void retrieve(size_t len)
    {
        if (len < readableBytes())
        {
            readerIndex_ += len; // 只读取了可读缓冲区数据的一部分，即是len，还剩下readerIndex+=len到writerIndex的可读没读
        }
        else // len==readableBytes()
        {
            retrieveAll();
        }
    }

    void retrieveAll()
    {
        readerIndex_ = writerIndex_ = kCheapPrepend;
    }

    // 把onMessage函数上报的Buffer数据，转成string类型的数据返回
    std::string retrieveAllAsString()
    {
        return retrieveAsString(readableBytes()); // 应用可读取数据长度
    }

    std::string retrieveAsString(size_t len)
    {
        std::string result(peek(), len);
        retrieve(len); // 上面一句已经把缓冲区中可读数据读出来，这里要对缓冲区进行复位操作
        return result;
    }

    void makeSpace(size_t len)
    {
        /**
         * kCheapPrepend  |  reader  |  writer  |
         * kCheapPrepend  |          len                    |
        */
        if (writableBytes() + prependableBytes() < len + kCheapPrepend)
        {
            buffer_.resize(writerIndex_ + len);
        }
        else
        {
            size_t readable = readableBytes();
            std::copy(begin() + readerIndex_,
                      begin() + writerIndex_,
                      begin() + kCheapPrepend);
            readerIndex_=kCheapPrepend;
            writerIndex_=readerIndex_+readable;
        }
    }

    std::vector<char> buffer_;
    size_t readerIndex_;
    size_t writerIndex_;
};