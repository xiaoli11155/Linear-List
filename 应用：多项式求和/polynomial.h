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

        // �ҵ�����λ��
        while (current->next != nullptr && current->next->exp > exp) {
            current = current->next;
        }

        // �����½ڵ�
        newNode->next = current->next;
        current->next = newNode;
    }
};

Node* add(Node*, Node*); // �ӷ�
Node* sub(Node*, Node*); // ����
void print_all(Node*);   // ��ӡ����ʽ
void freePolynomial(Node*); // �ͷŶ���ʽ������ڴ�

#endif