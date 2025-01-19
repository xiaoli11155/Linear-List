#include "seqList.h"

// ���캯��
template <class elemType>
seqList<elemType>::seqList(int initSize) {
    data = new elemType[initSize];
    maxSize = initSize;
    currentLength = 0;
}

// ��������
template <class elemType>
seqList<elemType>::~seqList() {
    delete[] data;
}

// ����б�
template <class elemType>
void seqList<elemType>::clear() {
    currentLength = 0;
}

// �����б���
template <class elemType>
int seqList<elemType>::length() const {
    return currentLength;
}

// ���ʵ� i ��Ԫ��
template <class elemType>
elemType seqList<elemType>::visit(int i) const {
    return data[i];
}

// �����б�
template <class elemType>
void seqList<elemType>::traverse() const {
    cout << endl;
    for (int i = 0; i < currentLength; i++) {
        cout << data[i] << ' ';
    }
    cout << endl;
}

// ����Ԫ��
template <class elemType>
int seqList<elemType>::search(const elemType& x) const {
    for (int i = 0; i < currentLength; i++) {
        if (data[i] == x) {
            return i;
        }
    }
    return -1;
}

// ����
template <class elemType>
void seqList<elemType>::doubleSpace() {
    elemType* tmp = data;
    maxSize *= 2;
    data = new elemType[maxSize];
    for (int i = 0; i < currentLength; i++) {
        data[i] = tmp[i];
    }
    delete[] tmp;
}

// ����Ԫ��
template <class elemType>
void seqList<elemType>::insert(int i, const elemType& x) {
    if (currentLength == maxSize) {
        doubleSpace();
    }
    for (int j = currentLength; j > i; j--) {
        data[j] = data[j - 1];
    }
    data[i] = x;
    currentLength++;
}

// ɾ��Ԫ��
template <class elemType>
void seqList<elemType>::remove(int i) {
    for (int j = i; j < currentLength - 1; j++) {
        data[j] = data[j + 1];
    }
    currentLength--;
}

// ��ʽʵ����ģ��
template class seqList<int>; // ��ʽʵ���� int ����