#include <iostream>

using namespace std;

//int* addEl(int* arr, int old_size, int el) {
//	int* new_arr = new int[old_size + 1];
//
//	for (int i = 0; i < old_size; i++)
//	{
//		new_arr[i] = arr[i];
//	}
//	new_arr[old_size] = el;
//
//	delete[] arr;
//
//	return new_arr;
//}

int main()
{
	srand(time(NULL));

	// Initialize matrix
	int n, m;
	cout << "Enter number of rows and cols: ";
	cin >> n >> m;

	int** matr = new int* [n];
	for (int i = 0; i < n; i++)
		matr[i] = new int[m];

	// Fill in with random elements
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matr[i][j] = rand() % 10 + 1;

	// Print the matrix
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << matr[i][j] << "\t";

		cout << endl;
	}

	// Loop through the matrix and find all satisfying elements; when an el is found, increment count
	int count = 0;
	for (int i = 0; i < n; i++)
		for (int j = 1; j < m - 1; j++)
			if (matr[i][j - 1] > matr[i][j] && matr[i][j + 1] < matr[i][j]) {
				count++;
				cout << "Found " << i+1 << ":" << j+1 << endl;
			}

	cout << "Number of elements: " << count;

	
	for (int i = 0; i < n; i++)
		delete[] matr[i];

	delete[] matr;
}