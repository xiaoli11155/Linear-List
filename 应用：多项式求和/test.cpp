#include"polynomial.h"


int main() {
	// 创建多项式 3x^2 + 2x + 1
	Node* poly1 = new Node();
	poly1->next = new Node(3, 2);
	poly1->next->next = new Node(2, 1);
	poly1->next->next->next = new Node(1, 0);

	// 创建多项式 -4x^3 + 3x^2 - 5
	Node* poly2 = new Node();
	poly2->next = new Node(-4, 3);
	poly2->next->next = new Node(3, 2);
	poly2->next->next->next = new Node(-5, 0);

	// 创建多项式 x^3 - x + 7
	Node* poly3 = new Node();
	poly3->next = new Node(1, 3);
	poly3->next->next = new Node(-1, 1);
	poly3->next->next->next = new Node(7, 0);

	// 打印多项式
	cout << "Polynomial 1: ";
	print_all(poly1);

	cout << "Polynomial 2: ";
	print_all(poly2);

	cout << "Polynomial 3: ";
	print_all(poly3);


	Node* addResult = add(poly1, poly2);

	Node* subResult = sub(poly1, poly3);

	cout << "Addition result of poly1 + poly2 :\n ";
	print_all(addResult);

	cout << "Subtraction result of poly1 - poly3 :\n ";
	print_all(subResult);

	return 0;
}
