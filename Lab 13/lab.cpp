#include "lab.h"


int isprime(int num)
{
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int IntMod::get_mod() {
    return this->mod;
}

int IntMod::max_mod(IntMod a) {
    if (this->mod >= a.mod)
        return this->mod;
    else
        return a.mod;
}

void IntMod::get()
{
    cout << this->num << endl;
}

void IntMod::set(int x)
{
    this->num = x;
}

IntMod IntMod::operator+(const IntMod& other)
{
    if (this->mod != other.mod) {
        if (other.mod < this->mod) {
            IntMod A(other);
            A.mod = this->mod;
            return IntMod((this->num + A.num) % this->mod, this->mod);
        }
        else {
            IntMod A(*this);
            A.mod = other.mod;
            return IntMod((other.num + A.num) % other.mod, other.mod);
        }
    }
    else return IntMod((this->num + other.num) % this->mod, this->mod);

}

IntMod IntMod::operator-(const IntMod& other)
{
    if (this->mod != other.mod) {
        if (other.mod < this->mod) {
            IntMod A(other);
            A.mod = this->mod;
            return IntMod((this->num - A.num) % this->mod, this->mod);
        }
        else {
            IntMod A(*this);
            A.mod = other.mod;
            return IntMod((other.num - A.num) % other.mod, other.mod);
        }
    }
    else return IntMod((this->num - other.num) % this->mod, this->mod);
}

IntMod IntMod::operator*(const IntMod& other)
{
    if (this->mod != other.mod) {
        if (other.mod < this->mod) {
            IntMod A(other);
            A.mod = this->mod;
            return IntMod((this->num * A.num) % this->mod, this->mod);
        }
        else {
            IntMod A(*this);
            A.mod = other.mod;
            return IntMod((other.num * A.num) % other.mod, other.mod);
        }
    }
    else return IntMod((this->num * other.num) % this->mod, this->mod);
}

IntMod IntMod::operator/(const IntMod& other)
{
    if (this->mod != other.mod) {
        if (other.mod < this->mod) {
            IntMod A(other);
            A.mod = this->mod;
            return IntMod((this->num / A.num) % this->mod, this->mod);
        }
        else {
            IntMod A(*this);
            A.mod = other.mod;
            return IntMod((other.num / A.num) % other.mod, other.mod);
        }
    }
    else return IntMod((this->num / other.num) % this->mod, this->mod);
}

bool IntMod::operator>(IntMod& other)
{
    if (this->mod == other.mod) {
        return (this->num % this->mod) > (other.num % this->mod);
    }
    else {
        if (other.mod < this->mod) {
            return (this->num % this->mod) > (other.num % this->mod);
        }
        else {
            return (this->num % other.mod) > (other.num % other.mod);
        }
    }
}

bool IntMod::operator<(IntMod& other)
{
    return (other > *this);
}

bool IntMod::operator>=(IntMod& other)
{
    return !(other > *this);
}

bool IntMod::operator<=(IntMod& other)
{
    return !(*this > other);
}

bool IntMod::operator==(IntMod& other)
{
    return !(*this > other) && !(other > *this);
}

bool IntMod::operator!=(IntMod& other)
{
    return (*this > other) || (other > *this);
}

IntMod const& IntMod::operator=(IntMod const& other)
{
    if (&other != this) {
        this->num = other.num;
        this->mod = other.mod;
    }
    return *this;
}


IntMod IntMod::operator+=(const IntMod& other)
{
    if (this->mod == other.mod)
    {
        this->num += (other.num) % this->mod;
        this->num = this->num % this->mod;
        this->mod = other.mod;
    }
    return *this;
}

IntMod IntMod::operator-=(const IntMod& other)
{
    if (this->mod == other.mod)
    {
        this->num -= (other.num) % this->mod;
        this->num = this->num % this->mod;
        this->mod = other.mod;
    }
    return *this;
}

IntMod IntMod::operator*=(const IntMod& other)
{
    if (this->mod == other.mod)
    {
        this->num *= (other.num) % this->mod;
        this->num = this->num % this->mod;
        this->mod = other.mod;
    }
    return *this;
}

IntMod IntMod::operator/=(const IntMod& other)
{
    if (this->mod == other.mod)
    {
        this->num /= (other.num) % this->mod;
        this->num = this->num % this->mod;
        this->mod = other.mod;
    }
    return *this;
}

ostream& operator<<(ostream& out, const IntMod& value) {
    return out << value.num;
}

istream& operator>>(istream& in, IntMod& value) {
    in >> value.num;
    in >> value.mod;
    return in;
}


// сравнение значений двух классов по модулю


int IntMod::gcd(IntMod& B) {
    int a = this->num, b = B.num;
    if (a < b) {
        swap(a, b);
    }
    while (a % b != 0) {
        a = a % b;
        swap(a, b);
    }
    if (this->mod >= B.mod)
        return b % this->mod;
    return b % B.mod;
}


int cmprsn(IntMod f, IntMod z) {
    if (f.mod > z.mod) {
        z.mod = f.mod;
    }
    else {
        f.mod = z.mod;
    }
    if (f.gcd(z) == 1) {
        for (int i = 1; i < f.mod; ++i) {
            if (((f.num * i) - z.num) % f.mod == 0) {
                return i;
            }
        }
    }
    return -1;
}
