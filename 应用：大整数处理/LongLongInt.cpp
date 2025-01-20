#include "LongLongInt.h"

LongLongInt::LongLongInt(const char* n) {
    const char* tmp; // 保存参数的绝对值
    switch (*n) {
    case '+': sign = '+'; tmp = n + 1; break;
    case '-': sign = '-'; tmp = n + 1; break;
    default: sign = '+'; tmp = n; break;
    }

    if (strcmp(tmp, "0") == 0) tmp = "";
    int len = strlen(tmp);

    num = new char[len + 1];
    for (int i = 0; i < len; i++) {
        num[len - i - 1] = tmp[i];
    }
    num[len] = '\0';
}

LongLongInt::LongLongInt(const LongLongInt& other) {
    sign = other.sign;
    num = new char[strlen(other.num) + 1];
    strcpy(num, other.num);
}

LongLongInt& LongLongInt::operator=(const LongLongInt& right) {
    if (this == &right) return *this;

    delete[] num;  // 使用 delete[] 释放数组
    sign = right.sign;
    num = new char[strlen(right.num) + 1];
    strcpy(num, right.num);
    return *this;
}

ostream& operator<<(ostream& os, const LongLongInt& obj) {
    if (strlen(obj.num) == 0) {
        os << 0;
    }
    else {
        if (obj.sign == '-') {
            os << obj.sign;  // 只输出负号
        }
        for (int i = strlen(obj.num) - 1; i >= 0; i--) {
            os << obj.num[i];  
        }
    }
    return os;
}

char* add(const char* s1, const char* s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int minLen = (len1 > len2 ? len2 : len1);
    int len = (len1 > len2 ? len1 : len2) + 1;
    int carry = 0;  // 保存进位
    int result;     // 当前位的运算结果

    char* num = new char[len + 1];
    int i;

    for (i = 0; i < minLen; i++) {
        result = (s1[i] - '0') + (s2[i] - '0') + carry;
        num[i] = (result % 10) + '0';
        carry = result / 10;
    }

    while (i < len1) {  // s2 先结束
        result = (s1[i] - '0') + carry;
        num[i] = (result % 10) + '0';
        carry = result / 10;
        i++;
    }

    while (i < len2) {  // s1 先结束
        result = (s2[i] - '0') + carry;
        num[i] = (result % 10) + '0';
        carry = result / 10;
        i++;
    }

    if (carry != 0) {
        num[i] = carry + '0';
        i++;
    }
    num[i] = '\0';

    return num;
}

char* sub(const char* s1, const char* s2) {
    if (!strcmp(s1, s2)) {
        char* num = new char[1];
        num[0] = '\0';
        return num;
    }

    int len1 = strlen(s1), len2 = strlen(s2);
    int minus = 0;  // 保存借位
    char* num = new char[len1 + 1];

    int i;
    for (i = 0; i < len2; i++) {
        int diff = (s1[i] - '0') - (s2[i] - '0') - minus;
        if (diff < 0) {
            diff += 10;
            minus = 1;
        }
        else {
            minus = 0;
        }
        num[i] = diff + '0';
    }

    while (i < len1) {
        int diff = (s1[i] - '0') - minus;
        if (diff < 0) {
            diff += 10;
            minus = 1;
        }
        else {
            minus = 0;
        }
        num[i] = diff + '0';
        i++;
    }

    // 压缩结果中高位的 0
    while (i > 0 && num[i - 1] == '0') {
        i--;
    }
    num[i] = '\0';

    return num;
}

bool great(const char* s1, const char* s2) {
    int len1 = strlen(s1), len2 = strlen(s2);

    if (len1 > len2) return true;
    if (len1 < len2) return false;

    for (int i = len1 - 1; i >= 0; i--) {
        if (s1[i] > s2[i]) return true;
        if (s1[i] < s2[i]) return false;
    }

    return false;
}

LongLongInt operator+(const LongLongInt& n1, const LongLongInt& n2) {
    LongLongInt n;
    if (n1.sign == n2.sign) {
        n.sign = n1.sign;
        n.num = add(n1.num, n2.num);
    }
    else if (great(n1.num, n2.num)) {
        n.sign = n1.sign;
        n.num = sub(n1.num, n2.num);
    }
    else {
        n.sign = n2.sign;
        n.num = sub(n2.num, n1.num);
    }
    return n;
}

LongLongInt operator-(const LongLongInt& n1, const LongLongInt& n2) {
    LongLongInt n(n2);
    if (n.sign == '+') n.sign = '-';
    else n.sign = '+';
    return n1 + n;
}