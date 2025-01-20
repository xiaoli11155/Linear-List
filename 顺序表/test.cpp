#include "seqList.h"

int main() {

    // ����һ�� seqList ����
    seqList<int> list;

    // ����Ԫ��
    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);
    list.insert(1, 10);

    // �����б�
    cout << "List after insertion:";
    list.traverse();

    // ɾ��Ԫ��
    list.remove(3);
    cout << "List after removing element at index 3:";
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
    cout << "Element at index 0: " << list.visit(0) << endl;

    //ɾ������0��Ԫ�ص�Ԫ��
    list.erase(0);
    cout << "List after erase(0) :";
    list.traverse();

    // ����б�
    list.clear();
    cout << "List after clearing:";
    list.traverse();

    return 0;
}

/*���н����
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