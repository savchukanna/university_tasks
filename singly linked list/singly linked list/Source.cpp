//Створити лінійний однозв’язний список, вивести  його.
//Якщо в списку є елемент із заданим ключем, вилучити його, а два наступні поміняти місцями.
//Поміняти у кожній пятірці елементів списку перший та пятий елемент місцями

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node =
		(struct Node*) malloc(sizeof(struct Node));

	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void print_list(struct Node* node)
{
	while (node != NULL)
	{
		cout << node->data << setw(3);
		node = node->next;
	}
}


void swap(struct Node** first, struct Node** second)
{
	struct Node* tmp = *first;
	*first = *second;
	*second = tmp;
}

void swap_nodes(struct Node** headr, int key1, int key2)
{
	if (key1 == key2) return;

	struct Node** first = headr;

	for (int i = 1; i <= key1 - 1; i++) {
		first = &(*first)->next;
	}

	if (*first == NULL) return;

	struct Node** second = headr;


	for (int i = 1; i <= key2 - 1; i++) {
		second = &(*second)->next;
	}


	if (*second == NULL) return;

	swap(first, second);
	swap(&(*first)->next, &(*second)->next);
}


Node* delete_item(Node* curr, int data) {
	Node* next;
	if (curr == NULL) {
		cout << "not found\n";
		return NULL;
	}
	else if (curr->data == data) {
		next = curr->next;
		free(curr);
		return next;
	}
	else {
		curr->next = delete_item(curr->next, data);
		return curr;
	}
}


int count(Node* head)
{
	Node* current = head;
	int count = 0;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}

int div_up(int x, int y)
{
	return (x - 1) / y + 1;
}


int main()
{
	struct Node* start = NULL;

	srand(time(NULL));
	int n;
	int key;
	do {
		cout << "Enter the number of items in the list: " << endl;
		cin >> n;
	} while (n <= 0);

	for (int i = 0; i < n; i++) {
		push(&start, rand() % 15);
	}

	cout << "\n List: ";
	print_list(start);

	cout << "\n Enter the number: " << endl;
	cin >> key;

	start = delete_item(start, key);

	cout << "\n New List: ";
	print_list(start);

	key = count(start) / 5;
	//cout << endl << count(start) << endl << key << endl;
	int key1 = 0;
	int key2 = 5;

	for (int i = 0; i < key; i++) {
		swap_nodes(&start, key1 + (5 * i), key2 + (5 * i));
		key1++;
		key2++;

	}

	cout << "\n New List with swapped elements: ";
	print_list(start);
	cout << endl;
	system("pause");
	return 0;
}