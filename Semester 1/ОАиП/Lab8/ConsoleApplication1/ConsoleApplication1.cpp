#include <iostream>

using namespace std;

//int find_min(int* arr, int size) {
//    int val = INT_MAX, ind;
//
//    for (int i = 0; i < size; i++)
//    {
//        if (arr[i] < val) 
//        {
//            val = arr[i];
//            ind = i;
//        }
//    }
//
//    return ind;
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

	if (n == m) {
		int val = INT_MIN;
		for (int i = 0, j = 0; i < n; i++, j++)
		{
			cout << "el " << i+1 << ":" << j+1 << " is " << matr[i][j] << endl;
			if (matr[i][j] > val) val = matr[i][j];
		}
		cout << "Res1: " << val << endl;

		val = INT_MIN;
		for (int i = 0, j = n - 1; i < n; i++, j--)
		{
			cout << "el " << i+1 << ":" << j+1 << " is " << matr[i][j] << endl;
			if (matr[i][j] > val) val = matr[i][j];
		}
		cout << "Res2: " << val << endl;
	}

	for (int i = 0; i < n; i++)
		delete[] matr[i];

	delete[] matr;
}