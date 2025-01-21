#include "polynomial.h"

int main() {
    // 创建多项式 3x^2 + 2x + 1
    Node* poly1 = new Node();
    poly1->insert(2, 1);        //次数输入时任意，insert会按从高到低插入链表
    poly1->insert(3, 2);
    poly1->insert(1, 0);

    // 创建多项式 -4x^3 + 3x^2 - 5
    Node* poly2 = new Node();
    poly2->insert(3, 2);
    poly2->insert(-4, 3);
    poly2->insert(-5, 0);

    // 创建多项式 x^3 - x + 7
    Node* poly3 = new Node();
    poly3->insert(7, 0);
    poly3->insert(1, 3);
    poly3->insert(-1, 1);
    
    cout << "Polynomial 1: ";
    print_all(poly1);

    cout << "Polynomial 2: ";
    print_all(poly2);

    cout << "Polynomial 3: ";
    print_all(poly3);

   
    Node* addResult = add(poly1, poly2);
    cout << "Addition result of poly1 + poly2:\n ";
    print_all(addResult);

    
    Node* subResult = sub(poly1, poly3);
    cout << "Subtraction result of poly1 - poly3:\n ";
    print_all(subResult);

    
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(poly3);
    freePolynomial(addResult);
    freePolynomial(subResult);

    return 0;
}