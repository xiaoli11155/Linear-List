#include "sLinkList.h"
#include <iostream>
using namespace std;

int main() {
    // ����һ�� sLinkList ����
    sLinkList<int> list;

    // ����Ԫ��
    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);

    // ��������
    cout << "List after insertion:";
    list.traverse(); // ���: 10 20 30

    // ɾ��Ԫ��
    list.remove(1); // ɾ�� 20
    cout << "List after removing element at index 1:";
    list.traverse(); // ���: 10 30

    // ����Ԫ��
    int index = list.search(30);
    if (index != -1) {
        cout << "Element 30 found at index: " << index << endl;
    }
    else {
        cout << "Element 30 not found." << endl;
    }

    // ����Ԫ��
    cout << "Element at index 0: " << list.visit(0) << endl; // ���: 10

    // �������
    list.clear();
    cout << "List after clearing:";
    list.traverse(); // ���: (��)

    return 0;
}