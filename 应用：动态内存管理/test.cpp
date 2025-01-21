#include "memory.h"
#include <iostream>

int main() {
    memory mem(100); // 初始化 100 个单元的内存

    cout << "Initial free memory:" << endl;
    mem.printFreeMemory();

    int addr1 = mem.malloc(20); // 分配 20 个单元
    int addr2 = mem.malloc(30); // 分配 30 个单元

    cout << "\nAfter allocating 20 and 30 units:" << endl;
    mem.printFreeMemory();

    mem.free(addr1, 20); // 释放 addr1 的 20 个单元

    cout << "\nAfter freeing 20 units:" << endl;
    mem.printFreeMemory();

    int addr3 = mem.malloc(50); // 分配 50 个单元

    cout << "\nAfter allocating 50 units:" << endl;
    mem.printFreeMemory();

    return 0;
}