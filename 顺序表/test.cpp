#include "seqList.h"

int main() {

    // 创建一个 seqList 对象
    seqList<int> list;

    // 插入元素
    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);
    list.insert(1, 10);

    // 遍历列表
    cout << "List after insertion:";
    list.traverse();

    // 删除元素
    list.remove(3);
    cout << "List after removing element at index 3:";
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
    cout << "Element at index 0: " << list.visit(0) << endl;

    //删除等于0号元素的元素
    list.erase(0);
    cout << "List after erase(0) :";
    list.traverse();

    // 清空列表
    list.clear();
    cout << "List after clearing:";
    list.traverse();

    return 0;
}

/*运行结果：
List after insertion:
10 10 20 30
List after removing element at index 3:
10 10 20
Element 30 not found.
Element at index 0: 10
List after erase(0) :
20
List after clearing:

*/