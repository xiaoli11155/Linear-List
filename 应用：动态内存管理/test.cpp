#include "memory.h"
#include <iostream>

int main() {
    memory mem(100); // ��ʼ�� 100 ����Ԫ���ڴ�

    cout << "Initial free memory:" << endl;
    mem.printFreeMemory();

    int addr1 = mem.malloc(20); // ���� 20 ����Ԫ
    int addr2 = mem.malloc(30); // ���� 30 ����Ԫ

    cout << "\nAfter allocating 20 and 30 units:" << endl;
    mem.printFreeMemory();

    mem.free(addr1, 20); // �ͷ� addr1 �� 20 ����Ԫ

    cout << "\nAfter freeing 20 units:" << endl;
    mem.printFreeMemory();

    int addr3 = mem.malloc(50); // ���� 50 ����Ԫ

    cout << "\nAfter allocating 50 units:" << endl;
    mem.printFreeMemory();

    return 0;
}