#ifndef LAB_13_
#define LAB_13_

#include <iostream>
using namespace std;

int isprime(int num);
int gcd(int a, int b);

class IntMod
{
private:

    int num;
    int mod;

public:

    IntMod(int num = 0, int mod = 1) : num(num% mod), mod(mod) {}

    IntMod operator+(const IntMod& other);
    IntMod operator-(const IntMod& other);
    IntMod operator*(const IntMod& other);
    IntMod operator/(const IntMod& other);
    IntMod operator+=(const IntMod& other);
    IntMod operator-=(const IntMod& other);
    IntMod operator*=(const IntMod& other);
    IntMod operator/=(const IntMod& other);

    bool operator>(IntMod& other);
    bool operator<(IntMod& other);
    bool operator>=(IntMod& other);
    bool operator<=(IntMod& other);
    bool operator==(IntMod& other);
    bool operator!=(IntMod& other);
    IntMod const& operator=(IntMod const& other);

    int max_mod(IntMod a);
    int get_mod();
    int gcd(IntMod& B);
    friend ostream& operator<<(ostream& os, const IntMod& value);
    friend istream& operator>>(istream& os, IntMod& value);

    void get();
    void set(int x);

    friend int cmprsn(IntMod f, IntMod z);
};

#endif
