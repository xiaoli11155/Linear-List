#ifndef MEMORY_H
#define MEMORY_H

#include<iostream>
using namespace std;

class memory {

	struct node {
		int start;  //起始地址
		int end;  //终止地址
		node* prev, * next;
		node(int s, int e, node* p = nullptr, node* n = nullptr) {
			start = s;
			end = e;
			prev = p;
			next = n;
		}
		node() { prev = nullptr; next = nullptr; }
	};


	node* head, *tail;


	public:
		memory(int capacity);
		int malloc(int size);
		void free(int start, int size);
		~memory();
		void printFreeMemory() const;

};


#endif
