#include "LongLongInt.h"

int main() {

    LongLongInt a("123456789");
    LongLongInt b("987654321");
    LongLongInt c = a + b;
    LongLongInt d = a - b;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << c << endl;
    cout << "a - b = " << d << endl;

    return 0;
}