#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
using namespace std;

class Node {
public:
    int coff, exp;
    Node* next;

    Node() : coff(0), exp(0), next(nullptr) {}
    Node(int n1, int n2, Node* p = nullptr) : coff(n1), exp(n2), next(p) {}

    
    void insert(int coff, int exp) {
        Node* newNode = new Node(coff, exp);
        Node* current = this;

        // 找到插入位置
        while (current->next != nullptr && current->next->exp > exp) {
            current = current->next;
        }

        // 插入新节点
        newNode->next = current->next;
        current->next = newNode;
    }
};

Node* add(Node*, Node*); // 加法
Node* sub(Node*, Node*); // 减法
void print_all(Node*);   // 打印多项式
void freePolynomial(Node*); // 释放多项式链表的内存

#endif