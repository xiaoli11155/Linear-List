#include "sLinkList.h"

int main() {
    
    sLinkList<int> list;

    // 插入元素
    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);

    // 遍历链表
    cout << "List after insertion:";
    list.traverse(); 

    // 删除元素
    list.remove(1); 
    cout << "List after removing element at index 1:";
    list.traverse(); 

    // 查找元素
    int index = list.search(30);
    if (index != -1) {
        cout << "Element 30 found at index: " << index << endl;
    }
    else {
        cout << "Element 30 not found." << endl;
    }

    // 访问元素
    cout << "Element at index 0: " << list.visit(0) << endl; // 输出: 10

    // 清空链表
    list.clear();
    cout << "List after clearing:";
    list.traverse(); 

    return 0;
}