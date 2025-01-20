#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
using namespace std;

class Node {
	public:
		int coff, exp;
		Node* next;

		Node() { next = nullptr; }
		Node(int n1,int n2,Node*p=nullptr):coff(n1),exp(n2),next(p){}
};

Node* add(Node*, Node*);
Node* sub(Node*, Node*);
void print_all(Node*);


#endif