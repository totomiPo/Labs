#include "lab8.h"

/*Рекурсивно описать функцию C(n, m) вычисления биномиального коэффициента по следующей формуле:
C(n, 0) = C(n, n) = 1;  C(n, m) = C(n - 1, m) + C(n - 1, m - 1) при 0 < m < n. 
Написать тестирующую программу к ней.*/

int main() 
{
	cout << "Hello. Calculation of the binomial coefficient C(n, m)" << '\n';
	cout << '\n';

	int n = 0, m = 0;
	cout << "Enter the n number: "; cin >> n;
	cout << "Enter the m number: "; cin >> m;
	if (m > n) 
	{
		cout << "m is less than n, repeat the input";
		return -1;
	}
	else if ((m < 0) || (n < 0)) {
		cout << "There cannot be negative values of m or n";
		return -2;
	}

	cout << '\n';
	cout << "-----------------------" << '\n';
	cout << "Result is C(n,m): " << bci(n, m) << endl;
	return 0;
}
