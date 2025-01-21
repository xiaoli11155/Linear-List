#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;
	node(int d, node* n = nullptr) { data = d; next = n; }
};

int main() {
	node* head, * tail;

	int n, num;		//n����,����num�����˳�Ȧ��
	cin >> n >> num;

	//��������
	head = tail = new node(0);
	for (int i = 1; i <=n; i++) {
		tail = tail->next = new node(i); //��ÿ���˱�ź��������
	}
	tail->next = head->next;  //ͷβ����,���ӵ�head�ĺ�һ��

	//���ɾ��
	node* current = head->next;//��ǰ�ڵ�
	node* prev = tail;//ǰһ���ڵ�

	while (current->next != current) {//����Ԫ�ض���1��
		for (int i = 1; i < num; i++) {
			prev = current;
			current = current->next;  //�����ƶ�һ�����
		}
		cout << current->data << "-";
		prev->next = current->next;  //������ǰ���
		delete current;
		current = prev->next;  //��������
	}
	cout << current->data << endl;
	delete current;

	return 0;
}