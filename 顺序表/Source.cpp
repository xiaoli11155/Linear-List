#include<list>
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