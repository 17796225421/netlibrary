#include "logger.h"
#include "Timestamp.h"

#include <iostream>

// 获取日志唯一的实例对象
Logger &Logger::instance()
{
    static Logger logger;
    return logger;
}

// 设置日志级别
void Logger::setLogLevel(int level)
{
    logLevel_ = level;
}

// 写日志  [级别信息] time : msg
void Logger::log(std::string msg)
{
    if (logLevel_ == INFO)
    {
        std::cout << "[INFO]";
    }
    else if (logLevel_ == ERROR)
    {
        std::cout << "[ERROR]";
    }
    else if (logLevel_ == FATAL)
    {
        std::cout << "FATAL";
    }
    else if (logLevel_ == DEBUG)
    {
        std::cout << "DEBUG";
    }

    // 打印时间
    std::cout << Timestamp::now().toString() << " : " << msg << std::endl;
}