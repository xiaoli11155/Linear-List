#include"polynomial.h"

Node* add(Node* exp1, Node* exp2) {
	Node* res, * p, * tmp;  //res��żӵĽ����pָ��res�ı�β

	res = p = new Node();

	exp1 = exp1->next;
	exp2 = exp2->next;

	while (exp1 != nullptr && exp2 != nullptr) {
		if (exp1->exp < exp2->exp) {
			p->next = new Node(exp2->coff, exp2->exp);
			exp2 = exp2->next;
		}
		else if (exp1->exp > exp2->exp) {
			p->next = new Node(exp1->coff, exp1->exp);
			exp1 = exp1->next;
		}
		else {
			int sumCoff = exp1->coff + exp2->coff;
			if (sumCoff != 0) {
				p->next = new Node(sumCoff, exp1->exp);
			}
			exp1 = exp1->next;
			exp2 = exp2->next;
		}
		p = p->next;
		
	}

	if (exp1 == nullptr) tmp = exp2;  //exp1�Ƚ���
	else tmp = exp1;  //exp2�Ƚ���

	while (tmp != nullptr) {
		p->next = new Node(tmp->coff, tmp->exp);
		tmp = tmp->next;
		p = p->next;
	}

	return res;
}

Node* sub(Node* exp1, Node* exp2) {
	Node* res, * p, * tmp;  
	res = p = new Node();
	exp1 = exp1->next;
	exp2 = exp2->next;
	while (exp1 != nullptr && exp2 != nullptr) {
		if (exp1->exp < exp2->exp) {
			p->next = new Node(exp2->coff, exp2->exp);
			exp2 = exp2->next;
		}
		else if (exp1->exp > exp2->exp) {
			p->next = new Node(exp1->coff, exp1->exp);
			exp1 = exp1->next;
		}
		else {
			int diffCoff = exp1->coff - exp2->coff;
			if (diffCoff != 0) {
				p->next = new Node(diffCoff, exp1->exp);
			}
			exp1 = exp1->next;
			exp2 = exp2->next;
		}
		p = p->next;
	}

	if (exp1 == nullptr) tmp = exp2; 
	else tmp = exp1;  

	while (tmp != nullptr) {
		p->next = new Node(tmp->coff, tmp->exp);
		tmp = tmp->next;
		p = p->next;
	}

	return res;
}


void print_all(Node* head) {
	Node* p = head->next;
	bool isFirstTerm = true; //�Ƿ�Ϊ��һ��

	//�ҵ���ߴ���
	int maxExp = 0;
	Node* temp = p;
	while (temp != nullptr) {
		if (temp->exp > maxExp) {
			maxExp = temp->exp;
		}
		temp = temp->next;
	}

	// �ӵʹε��ߴ����
	for (int exp = maxExp; exp >= 0; exp--) {
		temp = p;
		while (temp != nullptr) {
			if (temp->exp == exp) {
				//
				if (!isFirstTerm && temp->coff > 0) {
					cout << "+"; // ��ϵ����ǰ�� "+"
				}
				else if (temp->coff < 0) {
					cout << "-"; // ��ϵ����ǰ�� "-"
				}

				if (exp == 0 || (temp->coff != 1 && temp->coff != -1)) {
					if (temp->coff > 0) {
						cout << temp->coff; // ��ϵ��ֱ�����
					}
					else {
						cout << -temp->coff; // ��ϵ��ȡ�����
					}
				}

				// ���������ָ��
				if (exp > 0) {
					cout << "x";
					if (exp > 1) {
						cout << "^" << exp; // ָ������ 1 ʱ���ָ��
					}
				}

				isFirstTerm = false;
			}
			temp = temp->next;
		}
	}
	cout << endl;
}

