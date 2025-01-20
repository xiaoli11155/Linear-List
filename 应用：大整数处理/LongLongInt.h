#ifndef LONGLONGINT_H
#define LONGLONGINT_H

#include <iostream>
#include <cstring>

using namespace std;

class LongLongInt {
    friend LongLongInt operator+(const LongLongInt&, const LongLongInt&);
    friend ostream& operator<<(ostream&, const LongLongInt&);
    friend LongLongInt operator-(const LongLongInt&, const LongLongInt&);

private:
    char sign;  // 保存符号
    char* num;  // 逆序保存整数的绝对值

public:
    LongLongInt(const char* n = "");
    LongLongInt(const LongLongInt&);
    LongLongInt& operator=(const LongLongInt&);
    ~LongLongInt() { delete[] num; }  // 使用 delete[] 释放数组
};

// 工具函数
char* add(const char* s1, const char* s2);  // 同号，绝对值相加
char* sub(const char* s1, const char* s2);  // 异号，绝对值相减
bool great(const char* s1, const char* s2);  // 比较大小

#endif