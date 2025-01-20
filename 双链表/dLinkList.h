#ifndef DLINKLIST_H
#define DLINKLIST_H

#include "List.h"
#include <iostream>
using namespace std;

template<class elemType>
class dLinkList : public List<elemType> {
private:
    struct node {
        elemType data;
        node* next, * prev;

        node(const elemType& x, node* p = nullptr, node* n = nullptr) : data(x), prev(p), next(n) {}
        node() : next(nullptr),prev(nullptr) {}
        ~node() {}
    };

    node* head, * tail;
    int currentLength;

    node* move(int i) const;

public:
    dLinkList();
    ~dLinkList();
    void clear();
    int length() const;
    void insert(int i, const elemType& x);
    void remove(int i);
    int search(const elemType& x) const;
    elemType visit(int i) const;
    void traverse() const;
};

// 显式实例化声明
extern template class dLinkList<int>;

#endif // DLINKLIST_H