//Створити стек цілих чисел.Визначити чого більше у стеці від’ємних чи додатних чисел.

#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;

struct Stack {
	int info;
	Stack* next;
};

void show(Stack* top);
void push(Stack** top);
void func(Stack* top);

int main() {
	srand(time(NULL));
	int n;
	do {
		cout << "Enter the number of items in the stack: " << endl;
		cin >> n;
	} while (n <= 0);
	Stack* top = NULL;
	for (int i = 0; i < n; i++) {
		push(&top);
	}
	show(top);
	cout << endl;
	func(top);
	system("pause");
	return 0;
}

void show(Stack* top) {
	Stack* q = top;
	while (q) {
		cout << q->info << setw(3);
		q = q->next;
	}
}

void push(Stack** top) {
	Stack* q = new Stack();
	q->info = rand() % 10 - 5;

	if (top == NULL) {
		*top = q;
	}
	else {
		q->next = *top;
		*top = q;
	}
}

void func(Stack* top) {
	int pos = 0;
	int neg = 0;
	while (top) {
		if (top->info > 0) {
			pos++;
		}
		if (top->info < 0) {
			neg++;
		}
		top = top->next;
	}
	if (pos > neg) {
		cout << "More positive" << endl;
	}
	else {
		cout << "More negative" << endl;
	}
}