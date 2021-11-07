#pragma once

#include <iostream>
#include <string>

class Timestamp{
public:
    Timestamp();
    Timestamp(int64_t microSecondsSinceEpoch);
    static Timestamp now();
    std::string toString()const;

private:
    int64_t microSecondsSinceEpoch_;
};