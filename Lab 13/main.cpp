// �������� ����� IntMod ( �������� �� ������ �������� ����� )
// � ���������� + , +=, -, -=, =, == , != , > , < , >= , <= , *, *=, / , /=


/*
�� ���:
-�������� �� ������(���������� ��) ++
-�������� �� ��, ������� �� ����� ++
���:
��� �������� ����������: �� ���� ������ ������������� ����� 
����������� ��������� ��������(�, �) ������ �: �*� = � ��� � ++
����������� ����� ��� �� ������ ������ ���(�, �) ++
*/

#include "lab.h"

using namespace std;

int main()
{
    cout << "hello GIT!";
    int mod, num;
    IntMod A, B;
    cout << "Enter A number and mod:"; 
    if (!(cin >> A)) {
        cout << "Not number";
        return -1;
    }
    if (!(isprime(A.get_mod()))) {
        cout << "mod isn`t prime";
        return -1;
    }

    cout << "Enter B number and mod:"; 
    if (!(cin >> B)) {
        cout << "Not number";
        return -1;
    }
    if (!(isprime(B.get_mod()))) {
        cout << "mod isn`t prime";
        return -1;
    }

    cout << "\n" << A << " + " << B << " (mod " << A.max_mod(B) << ") = " << A + B << '\n';
    cout << "\n" << A << " - " << B << " (mod " << A.max_mod(B) << ") = " << A - B << '\n';
    cout << "\n" << A << " * " << B << " (mod " << A.max_mod(B) << ") = " << A * B << '\n';
    cout << "\n" << A << " / " << B << " (mod " << A.max_mod(B) << ") = " << A / B << '\n';
    if (A > B)
        cout << "\n" << A << " > " << B << " (mod " << A.max_mod(B) << ")\n";
    else if (A < B)
        cout << "\n" << A << " < " << B << " (mod " << A.max_mod(B) << ")\n";
    else
        cout << "\n" << A << " = " << B << " (mod " << A.max_mod(B) << ")\n";
    cout << "Comparison: " << '\n';
    cout << "\n" << A << " * " << cmprsn(A, B) << " = " << B << " (mod " << A.max_mod(B) << ")\n";
    cout << "GCD: " << '\n';
    cout << "(A, B)" << " (mod " << A.max_mod(B) << ") = " << A.gcd(B);
    return 0;
}