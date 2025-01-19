#include "sLinkList.h"

template <class elemType>
sLinkList<elemType>::sLinkList() {
    head = new node;
    currentLength = 0;
}

template <class elemType>
sLinkList<elemType>::~sLinkList() {
    clear();
    delete head;
}

template <class elemType>
void sLinkList<elemType>::clear() {
    node* p = head->next;
    node* q;
    head->next = nullptr;
    while (p != nullptr) {
        q = p->next;
        delete p;
        p = q;
    }
    currentLength = 0;
}

template <class elemType>
int sLinkList<elemType>::length() const {
    return currentLength;
}

template <class elemType>
typename sLinkList<elemType>::node* sLinkList<elemType>::move(int i) const {
    node* p = head;
    while (i > 0) {
        p = p->next;
        i--;
    }
    return p;
}

template <class elemType>
void sLinkList<elemType>::insert(int i, const elemType& x) {
    node* pos = move(i - 1);
    pos->next = new node(x, pos->next);
    currentLength++;
}

template <class elemType>
void sLinkList<elemType>::remove(int i) {
    node* pos = move(i - 1);
    node* delp = pos->next;
    pos->next = delp->next;
    delete delp;
    currentLength--;
}

template <class elemType>
int sLinkList<elemType>::search(const elemType& x) const {
    node* p = head->next;
    int i = 0;
    while (p != nullptr && p->data != x) {
        p = p->next;
        i++;
    }
    if (p == nullptr) return -1;
    else return i;
}


template <class elemType>
elemType sLinkList<elemType>::visit(int i) const {
    return move(i)->data;
}

template <class elemType>
void sLinkList<elemType>::traverse() const {
    node* p = head->next;
    cout << endl;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// ÏÔÊ½ÊµÀý»¯
template class sLinkList<int>;