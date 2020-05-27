//в дереві мінімальний елемент зменшити вдвічі, а максимальний збільшити вдвічі 

#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

struct Value {
	int x;
};

struct Node {
	Value y;
	Node* left;
	Node* right;
};

Node* max_value(Node* tree) {
	if (tree->right)
		return max_value(tree->right);
	else
		return tree;
}

Node* min_value(Node* tree) {
	if (tree->left)
		return min_value(tree->left);
	else
		return tree;
}

int input() {
	int num_of_elem;
	do {
		system("cls");
		cout << endl << "Enter the amount of elements: ";
		cin >> num_of_elem;
		while (getchar() != '\n');
	} while (num_of_elem < 1);
	return num_of_elem;
}

void add(Node** head, Value& x) {
	Node* p = *head;
	if (!p) {
		p = new Node;
		p->y.x = x.x;
		p->left = 0;
		p->right = 0;
		*head = p;
		return;
	}
	Node* pl = 0;
	bool ind = false;
	while (p && !ind) {
		pl = p;
		if (x.x == p->y.x) {
			ind = true;
		}
		else {
			if (x.x < p->y.x) {
				p = p->left;
			}
			else {
				p = p->right;
			}
		}
	}
	if (ind) {
		return;
	}
	Node* pnew = new Node;
	pnew->y.x = x.x;
	pnew->left = 0;
	pnew->right = 0;
	if (x.x < pl->y.x) {
		pl->left = pnew;
	}
	else {
		pl->right = pnew;
	}
}

void display(Node* s, int& i, COORD pos) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!s) {
		return;
	}
	else {
		pos.X -= 4;
		pos.Y += 2;
		display(s->left, ++i, pos);
		SetConsoleCursorPosition(hStdOut, pos);
		SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << s->y.x;
		pos.Y++;
		pos.X += 9;
		i--;
	}
	display(s->right, ++i, pos);
	pos.Y -= 2;
	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

bool is_in_tree(Node* s, int x) {
	if (s) {
		if (s->y.x == x) {
			return true;
		}
		is_in_tree(s->left, x);
		is_in_tree(s->right, x);
	}
	return false;
}

int main() {
	int amount = input();
	srand(time(0));
	Node* head = 0;
	for (int i = 0; i < amount; i++) {
		Value n;
		n.x = rand() % 101 - 50;
		while (is_in_tree(head, n.x)) {
			n.x = rand() % 101 - 50;
		}
		add(&head, n);
	}
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { 30, 2 };
	int i = 0;
	cout << endl << "TREE" << endl;
	display(head, i, pos);
	SetConsoleCursorPosition(hStdOut, pos);
	while (getchar() != '\n');
	Node* min = min_value(head);
	Node* max = max_value(head);
	min->y.x /= 2;
	max->y.x *= 2;
	system("cls");
	cout << endl << "TREE" << endl;
	i = 0;
	display(head, i, pos);
	cout << endl;
	pos = { 0, short(amount + 10) };
	SetConsoleCursorPosition(hStdOut, pos);
	system("pause");
	return 0;
}