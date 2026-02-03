#include <iostream>

using namespace std;
int stringLength(const char* const str) {
	int count = 0;
	while (str[count] != '\0') count++;
	return count;
}

int stringLengthRecursive(const char* const str) {
	if (str[0] == '\0') return 0;

	int res = stringLengthRecursive(str + 1);
	return res + 1;
}

int main()
{
	const int buffer = 201;
	char* str = new char[buffer];

	cout << "Input a string(max " << buffer - 1 << " chars long): ";
	
	cin.getline(str, buffer);

	cout << "Entered string: " << str << endl;
	cout << "======" << endl;
	cout << "Result: " << stringLength(str) << endl;
	cout << "Result(recursive): " << stringLengthRecursive(str) << endl;

	delete[] str;
}