#include <iostream>

using namespace std;

float max_val(float x, float y, float z = numeric_limits<float>::min()) {
	float currentNum = numeric_limits<float>::min();

	if (x > currentNum) currentNum = x;
	if (y > currentNum) currentNum = y;
	if (z > currentNum) currentNum = z;

	return currentNum;
}

float min_val(float x, float y, float z = numeric_limits<float>::max()) {
	float currentNum = numeric_limits<float>::max();

	if (x < currentNum) currentNum = x;
	if (y < currentNum) currentNum = y;
	if (z < currentNum) currentNum = z;

	return currentNum;
}

int main()
{
	float x, y, z, m;

	while (1) {
		cout << "Enter x: ";
		cin >> x;

		cout << "Enter y: ";
		cin >> y;

		cout << "Enter z: ";
		cin >> z;

		if (cin.good()) {
			if (max_val(x, y, z) == 0) {
				cout << "Error! Division by zero" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else break;
		}
		else {
			cout << "Wrong input! Try again" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}


	m = (min_val(z, x) + min_val(x, y)) / pow(max_val(x, y, z), 2);

	cout << "Result: " << m;
}