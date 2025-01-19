#include<list>
#include<iostream>
using namespace std;


template<class elemType>
class seqList :public list<elemType>
{
private:
	elemType* data;
	int currentLength;
	int maxSize;
	void doubleSpace();

public:
	seqList(int initSize = 10);
	~seqList();
	void clear();
	int length()const;
	void insert(int i, const elemType& x);
	void remove(int i);
	int search(const elemType& x)const;
	elemType visit(int i)const;
	void traverse()const;
};

template <class elemType>
seqList<elemType>::~seqList() {
	delete[] data;
}

template <class elemType>
void seqList<elemType>::clear() {
	currentLength = 0;
}

template <class elemType>
int seqList<elemType>::length()const {
	return currentLength;
}

template <class elemType>
elemType seqList<elemType>::visit(int i)const {
	return data[i];
}

template <class elemType>
void seqList<elemType>::traverse()const {
	cout << endl;
	for (int i = 0; i < currentLength; i++) {
		cout << data[i] << ' ';
	}
}


template <class elemType>
seqList<elemType>::seqList(int initSize) {
	data = new elemType[initSize];
	maxSize = initSize;
	currentLength = 0;
}

template <class elemType>
int  seqList<elemType>::search(const elemType& x)const {
	for (int i = 0; i < currentLength && data[i] != x; i++);
	if (i == currentLength)return -1;
	else return i;
}

template <class elemType>
void seqList<elemType>::doubleSpace() {
	elemType* tmp = data;
	maxSize *= 2;
	data = new elemType[maxSize];
	for (int i = 0; i < currentLength; i++) {
		data[i] = tmp[i];
	}
	delete[]tmp;
}

template <class elemType>
void seqList<elemType>::insert(int i, const elemType& x) {
	if (currentLength == maxSize)
		doubleSpace();
	for (int j = currentLength; j > i; i--) {
		data[j] = data[j - 1];
	}
	data[i] = x;
	currentLength++;
}

template <class elemType>
void seqList<elemType>::remove(int i) {
	for (int j = i; j < currentLength; j++) {
		data[j] = data[j + 1];
	}
	currentLength--;
}


