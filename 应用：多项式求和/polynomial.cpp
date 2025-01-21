#include "polynomial.h"

// ����ʽ�ӷ�
Node* add(Node* exp1, Node* exp2) {
    Node* res = new Node;   // ��������ͷ�ڵ�
    Node* p = res;          // ָ���������β��

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

    // ����ʣ�ಿ��
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

    // ����ʣ�ಿ��
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

// ��ӡ����ʽ���Ӹߴε��ʹΣ�
void print_all(Node* head) {
    Node* p = head->next;
    bool isFirstTerm = true; // �Ƿ�Ϊ��һ��

    while (p != nullptr) {
        if (!isFirstTerm && p->coff > 0) {
            cout << " + "; // ��ϵ����ǰ�� "+"
        }
        else if (p->coff < 0) {
            cout << " - "; // ��ϵ����ǰ�� "-"
        }

        // ���ϵ��
        if (p->exp == 0 || (p->coff != 1 && p->coff != -1)) {
            if (p->coff > 0) {
                cout << p->coff; // ��ϵ��ֱ�����
            }
            else {
                cout << -p->coff; // ��ϵ��ȡ�����
            }
        }

        // ���������ָ��
        if (p->exp > 0) {
            cout << "x";
            if (p->exp > 1) {
                cout << "^" << p->exp; // ָ������ 1 ʱ���ָ��
            }
        }

        isFirstTerm = false;
        p = p->next;
    }
    cout << endl;
}

// �ͷŶ���ʽ������ڴ�
void freePolynomial(Node* head) {
    Node* tmp;
    while (head != nullptr) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}