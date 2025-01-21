#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;
	node(int d, node* n = nullptr) { data = d; next = n; }
};

int main() {
	node* head, * tail;

	int n, num;		//n个人,报到num的人退出圈子
	cin >> n >> num;

	//建立链表
	head = tail = new node(0);
	for (int i = 1; i <=n; i++) {
		tail = tail->next = new node(i); //给每个人编号后插入链表
	}
	tail->next = head->next;  //头尾相连,连接到head的后一个

	//逐个删除
	node* current = head->next;//当前节点
	node* prev = tail;//前一个节点

	while (current->next != current) {//表中元素多于1个
		for (int i = 1; i < num; i++) {
			prev = current;
			current = current->next;  //往后移动一个结点
		}
		cout << current->data << "-";
		prev->next = current->next;  //跳过当前结点
		delete current;
		current = prev->next;  //继续报数
	}
	cout << current->data << endl;
	delete current;

	return 0;
}