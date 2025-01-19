#ifndef SEQLIST_H
#define SEQLIST_H

#include "List.h"
#include <iostream>
using namespace std;

template<class elemType>
class seqList : public List <elemType> {
private:
    elemType* data;
    int currentLength;
    int maxSize;
    void doubleSpace();

public:
    seqList(int initSize = 10);
    ~seqList();
    void clear();
    int length() const;
    void insert(int i, const elemType& x);
    void remove(int i);
    int search(const elemType& x) const;
    elemType visit(int i) const;
    void traverse() const;
    void erase(int i);
};

// ������ʽʵ����
extern template class seqList<int>; // ��ʽʵ���� int ����

#endif // SEQLIST_H