#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> v;
	cout << "the initial size of v is:" << v.size() << endl;
	cout << "the initial capacity of v is:" << v.capacity() << endl;

	v.push_back(2);//将2添加到表尾
	cout << "\nafter push 2, size of v is:" << v.size() << "\ncapacity of v is:" << v.capacity() << endl;

	v.push_back(3);
	cout << "\nafter push 3, size of v is:" << v.size() << "\ncapacity of v is:" << v.capacity() << endl;

	v.push_back(4);
	cout << "\nafter push 4, size of v is:" << v.size() << "\ncapacity of v is:" << v.capacity() << endl;

	cout << "\nthe size of v is:" << v.size() << "\nthe capacity of v is:" << v.capacity() << endl;


	//下标访问
	cout << "\nthe content of v using []:";
	for (int i = 0; i < v.size(); i++)cout << v[i] << " ";
	cout << endl;

	//迭代器访问
	cout << "\nthe content of v using iterator notation:";
	vector<int>::const_iterator p;
	for (p = v.begin(); p != v.end(); p++) {
		cout << *p << " ";
	}
	cout << endl;
	return 0;

};