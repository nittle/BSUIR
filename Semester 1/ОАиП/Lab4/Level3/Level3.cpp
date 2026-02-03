#include <iostream>

using namespace std;

struct dynamic_arr {
	int* p;
	int size;
};

void swap(int* arr, int index1, int index2) {
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

void bubbleSort(int* arr, int size) {
	for (int i = 0; i < size - 1; i++)
	{
		bool swapped = false;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}

		if (!swapped) break;
	}
}

dynamic_arr removeDuplicates(int* arr, int size) {
	bubbleSort(arr, size);
	int newSize = size;

	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] == arr[i + 1]) {
			newSize--;
		}
	}

	int* newArr = new int[newSize];
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != arr[i + 1]) {
			newArr[j] = arr[i];
			j++;
		}
	}

	dynamic_arr str;
	str.size = newSize;
	str.p = newArr;

	return str;
}

void printArray(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int size, choice;

	cout << "Enter number of elms: ";
	cin >> size;

	cout << "How to fill the array(1 - from keybr, 2 - with rand nums)?: ";
	cin >> choice;

	int* arr = new int[size];

	switch (choice)
	{
	case 1:
		cout << "Input nums separated with space: ";
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}
		cin.clear();
		cin.ignore(10000, '\n');
		break;
	case 2:
		srand(time(NULL));
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 10;
		}
		break;
	default:
		cout << "Wrong input!";
		return 0;
	}

	printArray(arr, size);

	dynamic_arr newArr = removeDuplicates(arr, size);
	delete[] arr;

	cout << "==========" << endl;
	cout << "Removed " << size - newArr.size << " elements" << endl;
	printArray(newArr.p, newArr.size);
}