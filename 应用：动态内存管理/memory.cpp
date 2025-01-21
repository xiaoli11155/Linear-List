#include"memory.h"

memory::memory(int capacity) {		//初始时有一整块完整的空闲空间
	head = new node;
	head->next = new node(0, capacity - 1, head);
	head->next->next = tail = new node;
	tail->prev = head->next;
}

memory::~memory() {
	node* p = head, * q;
	while (p != nullptr) {
		q = p->next;
		delete p;
		p = q;
	}
}

int memory::malloc(int size) {	//寻找一块足够大的空间，如果恰好与所申请空间一样大，则将此节点删除，否则在该结点中扣除所申请的空间
	node* p = head->next;
	int returnValue;  //申请到空间的起始地址

	while (p != tail && p->end - p->start + 1 < size)p = p->next;
	if (p == tail)return -1;
	else returnValue = p->start;

	if (p->end - p->start + 1 == size) {
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
	}
	else p->start += size;

	return returnValue;
}

void memory::free(int start, int size) {
	node* p = head->next, * np;
	while (p != tail && p->start < start)p = p->next;//找到比释放空间地址大的第一个结点

	if (p != tail && start + size == p->start) {	//释放空间与p结点可以连成一片
		p->start = start;
		np = p;
	}
	else {
		np = new node(start, start + size - 1, p->prev, p);  //在p前面新建一个结点
		p->prev->next = np;
		p->prev = np;
	}

	//能否和前一结点连成一片
	p = np->prev;
	if (p->end + 1 == np->start) {
		p->end = np->end;
		p->next = np->next;
		np->next->prev = p;
		delete np;
	}

}

void memory::printFreeMemory() const {
	node* p = head->next;

	cout << "Free memory blocks:" << endl;
	while (p != tail) {
		cout << "Start: " << p->start << ", End: " << p->end << ", Size: " << p->end - p->start + 1 << endl;
		p = p->next;
	}

	if (head->next == tail) {
		cout << "No free memory available." << endl;
	}
}

