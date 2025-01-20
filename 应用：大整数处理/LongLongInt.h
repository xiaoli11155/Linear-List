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
    char sign;  // �������
    char* num;  // ���򱣴������ľ���ֵ

public:
    LongLongInt(const char* n = "");
    LongLongInt(const LongLongInt&);
    LongLongInt& operator=(const LongLongInt&);
    ~LongLongInt() { delete[] num; }  // ʹ�� delete[] �ͷ�����
};

// ���ߺ���
char* add(const char* s1, const char* s2);  // ͬ�ţ�����ֵ���
char* sub(const char* s1, const char* s2);  // ��ţ�����ֵ���
bool great(const char* s1, const char* s2);  // �Ƚϴ�С

#endif