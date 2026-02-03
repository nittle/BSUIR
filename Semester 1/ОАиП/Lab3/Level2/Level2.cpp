#include <iostream>

using namespace std;

//int fact(int n) {
//	if (n == 0) return 1;
//
//	return n * fact(n - 1);
//}

float s(float x, int n) {
	float result = 1, p = 1;

	for (int k = 1; k < n; k++)
	{
		p = p * cos(k * x) / cos((k - 1) * x) / k;
		result += p;
	}

	return result;
	
	/*for (int k = 0; k < n; k++)
		result += cos(k * x) / fact(k);

	return result;*/
}

float y(float x) {
	return exp(cos(x)) * cos(sin(x));
}

int main()
{
	float a, b, h;
	int n;

	while (1) {
		cout << "Enter a: ";
		cin >> a;
		cout << "Enter b: ";
		cin >> b;
		cout << "Enter h: ";
		cin >> h;
		cout << "Enter n: ";
		cin >> n;

		if (cin.good()) break;
		else {
			cin.clear();
			cin.ignore(10000, '\n');
		}
   }

	float x = a;
	cout << "i\t\tx\t\tS(x)\t\tY(x)\t\t|Y(x) - S(x)|" << endl;

	for (int i = 1; x < b + h; x += h, i++)
	{
		float y_res = y(x), s_res = s(x, n);
		cout << i << "\t\t" << x << "\t\t" << s_res << "\t\t" << y_res << "\t\t" << abs(y_res - s_res) << "\t\t" << endl;

		//cout << "x" << i << " = " << x << "; S = " << s(x, n) << "; Y = " << y(x) << ";" << endl;
	}
}