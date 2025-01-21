#include"memory.h"

memory::memory(int capacity) {		//��ʼʱ��һ���������Ŀ��пռ�
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

int memory::malloc(int size) {	//Ѱ��һ���㹻��Ŀռ䣬���ǡ����������ռ�һ�����򽫴˽ڵ�ɾ���������ڸý���п۳�������Ŀռ�
	node* p = head->next;
	int returnValue;  //���뵽�ռ����ʼ��ַ

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
	while (p != tail && p->start < start)p = p->next;//�ҵ����ͷſռ��ַ��ĵ�һ�����

	if (p != tail && start + size == p->start) {	//�ͷſռ���p����������һƬ
		p->start = start;
		np = p;
	}
	else {
		np = new node(start, start + size - 1, p->prev, p);  //��pǰ���½�һ�����
		p->prev->next = np;
		p->prev = np;
	}

	//�ܷ��ǰһ�������һƬ
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

