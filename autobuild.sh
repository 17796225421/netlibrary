#!/bin/bash

set -e

# 如果没有build目录，创建该目录
if [ ! -d `pwd`/build ]; then
    mkdir `pwd`/build
fi

rm -rf `pwd`/build/*

cd `pwd`/build &&
    cmake .. &&
    make

# 回到项目根目录
cd ..

# 把头文件拷贝到 /usr/include/netlibrary  so库拷贝到 /usr/lib    PATH
if [ ! -d /usr/include/netlibrary ]; then 
    mkdir /usr/include/netlibrary
fi

for header in `ls *.h`
do
    cp $header /usr/include/netlibrary
done

cp `pwd`/lib/libnetlibrary.so /usr/lib

ldconfig