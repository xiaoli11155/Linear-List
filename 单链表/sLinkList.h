#ifndef SLINKLIST_H
#define SLINKLIST_H

#include "List.h"
#include <iostream>
using namespace std;

template<class elemType>
class sLinkList : public List<elemType> {
private:
    struct node {
        elemType data;
        node* next;

        node(const elemType& x, node* n = nullptr) : data(x), next(n) {}
        node() : next(nullptr) {}
        ~node() {}
    };

    node* head;
    int currentLength;

    node* move(int i) const;

public:
    sLinkList();
    ~sLinkList();
    void clear();
    int length() const;
    void insert(int i, const elemType& x);
    void remove(int i);
    int search(const elemType& x) const;
    elemType visit(int i) const;
    void traverse() const;
};

// 显式实例化声明
extern template class sLinkList<int>;

#endif // SLINKLIST_H