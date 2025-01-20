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
	pos->prev - next = pos->next;
	pos->next->prev = pos->prev;
	delete pos;
	currentLength--;
}
