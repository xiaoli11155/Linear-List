#include"dLinkList.h"

template <class elemType>
dLinkList<elemType>::dLinkList() {
	head = new node;
	head->next = tail = new node;
	tail->prev = head;
	currentLength = 0;
}

template <class elemType>
typename dLinkList<elemType>::node* dLinkList<elemType>::move(int i) const {
	node* p = head;
	while (i >= 0) {
		p = p->next;
		i--;
	}
	return p;
}

template <class elemType>
void dLinkList<elemType>::insert(int i, const elemType& x) {
	node* pos, * tmp;
	pos = move(i);
	tmp = new node(x, pos->prev, pos);
	pos->prev->next = tmp;
	pos->prev = tmp;
	currentLength++;
}

template <class elemType>
void dLinkList<elemType>::remove(int i) {
	node* pos;
	pos = move(i);
	pos->prev -> next = pos->next;
	pos->next->prev = pos->prev;
	delete pos;
	currentLength--;
}

template <class elemType>
void dLinkList<elemType>::clear() {
	node* p = head->next, * q;
	head->next = tail;
	tail->prev = head;
	while (p != tail) {
		q = p->next;
		delete p;
		p = q;
	}
	currentLength = 0;
}

template <class elemType>
int dLinkList<elemType>::length()const {
	return currentLength;
}

template <class elemType>
int dLinkList<elemType>::search(const elemType& x)const {
	node* p = head->next;
	int i;
	for ( i = 0; p != tail && p-> data != x; i++)p = p->next;
	if (p == tail)return -1;
	else return i;
}

template <class elemType>
elemType dLinkList<elemType>::visit(int i)const{
	return move(i)->data;
}

template <class elemType>
void dLinkList<elemType>::traverse()const {
	node* p = head->next;
	cout << endl;
	while (p != tail) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

template <class elemType>
dLinkList<elemType>::~dLinkList() {
	clear();
	delete head;
	delete tail;
}


template class dLinkList<int>;

