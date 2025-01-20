#include<iostream>
#include<list>
using namespace std;

template<class object>
void printall(const list<object>& v);


int main() {
	list<int>v1;

	v1.push_front(1); v1.push_front(2);
	v1.push_back(4); v1.push_back(3);
	printall(v1);


	list<int>::iterator itr = v1.begin(), itre = v1.end();
	for (int i = 5; itr != itre; i++, itr++) {
		v1.insert(itr, i);//返回值为指向新插入元素的迭代器
	}
	printall(v1);


	return 0;
}

template<class object>
void printall(const list<object>& v) {
	if (v.empty())cout << "\nlist is empty";
	else {
		typename list<object>::const_iterator itr,itre;
		itr = v.begin();
		itre = v.end();
		do{
			cout << *itr << " ";
			itr++;
		} while (itr != itre);
	}
	cout << endl;
}
