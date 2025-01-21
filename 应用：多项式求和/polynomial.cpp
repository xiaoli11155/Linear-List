#include "polynomial.h"

// 多项式加法
Node* add(Node* exp1, Node* exp2) {
    Node* res = new Node;   // 结果链表的头节点
    Node* p = res;          // 指向结果链表的尾部

    exp1 = exp1->next; 
    exp2 = exp2->next; 

    while (exp1 != nullptr && exp2 != nullptr) {
        if (exp1->exp < exp2->exp) {
            p->next = new Node(exp2->coff, exp2->exp);
            exp2 = exp2->next;
        }
        else if (exp1->exp > exp2->exp) {
            p->next = new Node(exp1->coff, exp1->exp);
            exp1 = exp1->next;
        }
        else {
            int sumCoff = exp1->coff + exp2->coff;
            if (sumCoff != 0) { 
                p->next = new Node(sumCoff, exp1->exp);
                p = p->next; 
            }
            exp1 = exp1->next;
            exp2 = exp2->next;
        }
        if (p->next != nullptr) {
            p = p->next;
        }
    }

    // 处理剩余部分
    Node* remaining = (exp1 == nullptr) ? exp2 : exp1;
    while (remaining != nullptr) {
        p->next = new Node(remaining->coff, remaining->exp);
        remaining = remaining->next;
        p = p->next;
    }

    return res;
}


Node* sub(Node* exp1, Node* exp2) {
    Node* res = new Node();
    Node* p = res;          

    exp1 = exp1->next; 
    exp2 = exp2->next; 

    while (exp1 != nullptr && exp2 != nullptr) {
        if (exp1->exp < exp2->exp) {
            p->next = new Node(-exp2->coff, exp2->exp); 
            exp2 = exp2->next;
        }
        else if (exp1->exp > exp2->exp) {
            p->next = new Node(exp1->coff, exp1->exp);
            exp1 = exp1->next;
        }
        else {
            int diffCoff = exp1->coff - exp2->coff; 
            if (diffCoff != 0) { 
                p->next = new Node(diffCoff, exp1->exp);
                p = p->next; 
            }
            exp1 = exp1->next;
            exp2 = exp2->next;
        }
        if (p->next != nullptr) {
            p = p->next;
        }
    }

    // 处理剩余部分
    while (exp1 != nullptr) {
        p->next = new Node(exp1->coff, exp1->exp);
        exp1 = exp1->next;
        p = p->next;
    }
    while (exp2 != nullptr) {
        p->next = new Node(-exp2->coff, exp2->exp); 
        exp2 = exp2->next;
        p = p->next;
    }

    return res;
}

// 打印多项式（从高次到低次）
void print_all(Node* head) {
    Node* p = head->next;
    bool isFirstTerm = true; // 是否为第一项

    while (p != nullptr) {
        if (!isFirstTerm && p->coff > 0) {
            cout << " + "; // 正系数项前加 "+"
        }
        else if (p->coff < 0) {
            cout << " - "; // 负系数项前加 "-"
        }

        // 输出系数
        if (p->exp == 0 || (p->coff != 1 && p->coff != -1)) {
            if (p->coff > 0) {
                cout << p->coff; // 正系数直接输出
            }
            else {
                cout << -p->coff; // 负系数取反输出
            }
        }

        // 输出变量和指数
        if (p->exp > 0) {
            cout << "x";
            if (p->exp > 1) {
                cout << "^" << p->exp; // 指数大于 1 时输出指数
            }
        }

        isFirstTerm = false;
        p = p->next;
    }
    cout << endl;
}

// 释放多项式链表的内存
void freePolynomial(Node* head) {
    Node* tmp;
    while (head != nullptr) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}