//Відсортувати заштриховану частину матриці за спаданням методом "бульбашка" та шейкер-сортуванням.Порівняти час виконання 

#include <iostream>
#include <ctime>

using namespace std;

int get_elem_of_arr();
void random(int**, int);
int** create_matrix(int);
void print(int**, int);
void buble_sort(int**, int*, int);
void shaker_sort(int** , int* , int);
int get_number_of_elements(int);

int get_elem_of_arr() {

	int quan;
	do {
		cout << "Input the quantity of elements: ";
		cin >> quan;
	} while (quan <= 0);
	cout << endl;
	return quan;
}

void random(int** matrix, int size) {
	srand(time(0));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = rand() % 9 + 1;
		}
	}
}

int** create_matrix(int size) {
	int** arr = new int* [size];
	for (int i = 0; i < size; i++) {
		arr[i] = new int[size];
	}
	return arr;
}

void print(int** matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void buble_sort(int** matrix, int* arr, int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		for (int j = size - 1; (i < size / 2) ? j >= size - 1 - i : j >= i; j--) {
			arr[count] = matrix[i][j];
			count++;
		}
	}
	//sort descending
	bool exit = false;
	while (!exit) {
		exit = true;
		for (int j = 0; j < count - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				int swap = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = swap;
				exit = false;
			}
		}
	}

	count = 0;
	for (int i = 0; i < size; i++) {
		for (int j = size - 1; (i < size / 2) ? j >= size - 1 - i : j >= i; j--) {
			matrix[i][j] = arr[count];
			count++;
		}
	}
}

void shaker_sort(int** matrix, int* arr, int size) {
	int counter = 0;
	for (int i = 0; i < size; i++) {
		for (int j = size - 1; (i < size / 2) ? j >= size - 1 - i : j >= i; j--) {
			arr[counter] = matrix[i][j];
			counter++;
		}
	}


	bool swapped = false;
	int count = 0;
	int count2 = 0;
	for (int i = counter - 1; i > 0; i--) {
		swapped = false;
		for (int j = i; j > counter - 1 - i; j--) {
			if (arr[j] > arr[j - 1]) {
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				swapped = true;
				count2++;
			}
		}
		for (int j = counter - i; j < i; j++) {
			if (arr[j] < arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = true;
				count2++;
			}

		}
		if (!swapped) {
			break;
		}
		counter++;
	}


	counter = 0;
	for (int i = 0; i < size; i++) {
		for (int j = size - 1; (i < size / 2) ? j >= size - 1 - i : j >= i; j--) {
			matrix[i][j] = arr[counter];
			counter++;
		}
	}
}

int get_number_of_elements(int size) {
	int amount = 0;
	for (int i = size; i > 0; i -= 2) {
		amount = amount + i;
	}
	return amount;
}

int main() {
	int size = get_elem_of_arr();
	int** matrix = create_matrix(size);
	random(matrix, size);
	print(matrix, size);
	int sizeOfTempArray = get_number_of_elements(size);
	int* arr = new int[sizeOfTempArray];

	cout << "Bubble sort: ";
	buble_sort(matrix, arr, size);
	cout << "\nTime: " << clock() / 1000.0 << endl;
	cout << endl;
	print(matrix, size);

	cout << "Shaker sort: ";
	shaker_sort(matrix, arr, size);
	cout << "\nTime: " << clock() / 1000.0 << endl;
	cout << endl;
	print(matrix, size);

	for (int i = 0; i < size; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	delete[] arr;

	system("pause");
	return 0;
}