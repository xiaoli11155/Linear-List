#include "sLinkList.h"

int main() {
    
    sLinkList<int> list;

    // ����Ԫ��
    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);

    // ��������
    cout << "List after insertion:";
    list.traverse(); 

    // ɾ��Ԫ��
    list.remove(1); 
    cout << "List after removing element at index 1:";
    list.traverse(); 

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
    list.traverse(); 

    return 0;
}