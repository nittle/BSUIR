#include <iostream>

using namespace std;
int main()
{
	const int size = 200;
	char* str = new char[size] {};

	cout << "Input a string: ";

	char ch;
	int i = 0;
	while (cin.get(ch)) {
		if (ch == '\n') break;
			
		str[i] = ch;
		i++;
	}

	int seq_start = 0, seq_count = 0;
	for (int i = 0; i < size; i++)
	{
		if (str[i] == ' ' || str[i] == NULL) {
			seq_count++;
			int length = 0, count = 0;
			for (int j = seq_start; j < i; j++)
			{
				length++;
			}

			if (length % 2 != 0) {
				for (int j = seq_start; j < i; j++)
					if (str[j] == '1') {
						count++;
					}
				cout << "Length: " << length << "\tCount: " << count << "\tSeq. num: " << seq_count;
			}
			else {
				cout << "Length: " << length << "\tCount: -\tSeq. num: " << seq_count;
			}


			cout << endl;
			seq_start = i + 1;
		}
		
		if (str[i] == NULL) break;
	}

	cout << str[i];
}