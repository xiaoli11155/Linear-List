#include "seqList.h"

// 构造函数
template <class elemType>
seqList<elemType>::seqList(int initSize) {
    data = new elemType[initSize];
    maxSize = initSize;
    currentLength = 0;
}

// 析构函数
template <class elemType>
seqList<elemType>::~seqList() {
    delete[] data;
}

// 清空列表
template <class elemType>
void seqList<elemType>::clear() {
    currentLength = 0;
}

// 返回列表长度
template <class elemType>
int seqList<elemType>::length() const {
    return currentLength;
}

// 访问第 i 个元素
template <class elemType>
elemType seqList<elemType>::visit(int i) const {
    return data[i];
}

// 遍历列表
template <class elemType>
void seqList<elemType>::traverse() const {
    cout << endl;
    for (int i = 0; i < currentLength; i++) {
        cout << data[i] << ' ';
    }
    cout << endl;
}

// 查找元素
template <class elemType>
int seqList<elemType>::search(const elemType& x) const {
    for (int i = 0; i < currentLength; i++) {
        if (data[i] == x) {
            return i;
        }
    }
    return -1;
}

// 扩容
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

// 插入元素
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

// 删除元素
template <class elemType>
void seqList<elemType>::remove(int i) {
    for (int j = i; j < currentLength - 1; j++) {
        data[j] = data[j + 1];
    }
    currentLength--;
}

// 显式实例化模板
template class seqList<int>; // 显式实例化 int 类型