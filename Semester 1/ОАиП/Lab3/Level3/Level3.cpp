#include <iostream>

using namespace std;

int fact(unsigned n) {
	if (n == 0) return 1;

	return n * fact(n - 1);
}

float y(float x) {
	return exp(cos(x)) * cos(sin(x));
}

auto s(float x) {
	float value = 0;
	int n = 0;
	float y_val = y(x);

	while(abs(value - y_val) >= 0.001)
	{
		value += cos(n * x) / fact(n);
		n++;
	}

	struct res { float result; int num_of_iter; };
	return res { value, n };
}

int main()
{
	float a, b, h;

	while (1) {
		cout << "Enter a: ";
		cin >> a;
		cout << "Enter b: ";
		cin >> b;
		cout << "Enter h: ";
		cin >> h;

		if (cin.good()) break;
		else {
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}

	float x = a;
	cout << "i\t\tx\t\tS(x)\t\tn\t\tY(x)\t\t|Y(x) - S(x)|" << endl;

	for (int i = 1; x < b + h; x += h, i++)
	{
		auto s_res = s(x);
		float y_res = y(x);
		cout << i << "\t\t" << x << "\t\t" << s_res.result << "\t\t" << s_res.num_of_iter << "\t\t" << y_res << "\t\t" << abs(y_res - s_res.result) << endl;
		//cout << "x" << i << " = " << x << "; S = " << s(x, n) << "; Y = " << y(x) << ";" << endl;
	}
}