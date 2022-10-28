#ifndef polynomial_h
#define polynomial_h

#include<iostream>
using namespace std;

class polynomial
{
private:
    int n;
    double *heso;
public:
    polynomial(int = 0);
    polynomial(const polynomial &);
    polynomial(int, double *);
    ~polynomial();
    polynomial operator + (const polynomial &);
    polynomial operator - (const polynomial &);
    long double operator () (double);
    double & operator [] (int);
    const polynomial & operator = (const polynomial &);
    friend istream & operator >> (istream &, polynomial &);
    friend ostream & operator << (ostream &, const polynomial &);
};

polynomial::polynomial(int size) {
    n = size;
    heso = new double[n + 1];
    for (int i = 0; i <= n; i++)
        heso[i] = 0;
}

polynomial::polynomial(int size, double * arr) {
    n = size;
    heso = new double[n + 1];
    for (int i = 0; i <= n; i++)
        heso[i] = arr[i];
}

polynomial::polynomial(const polynomial & pl) {
    n = pl.n;
    heso = new double[n + 1];
    for (int i = 0; i <= n; i++)
        heso[i] = pl.heso[i];
}

polynomial::~polynomial() {
    delete [] heso;
}

polynomial polynomial::operator + (const polynomial & p) {
    int size = max(p.n, n);
    double *arr = new double[size + 1];
    int i1 = n, i2 = p.n;
    for (int i = 0; i <= min(p.n, n); i++) {
        arr[max(i1, i2)] = heso[i1] + p.heso[i2];
        i1--, i2--;
    }
    while (i1 >= 0) {
        arr[i1] = heso[i1];
        i1--;
    }
    while (i2 >= 0) {
        arr[i2] = heso[i2];
        i2--;
    }
    return polynomial(size, arr);
}

polynomial polynomial::operator - (const polynomial & p) {
    int size = max(p.n, n);
    double *arr = new double[size + 1];
    int i1 = n, i2 = p.n;
    for (int i = 0; i <= min(p.n, n); i++) {
        arr[max(i1, i2)] = heso[i1] - p.heso[i2];
        i1--, i2--;
    }
    while (i1 >= 0) {
        arr[i1] = heso[i1];
        i1--;
    }
    while (i2 >= 0) {
        arr[i2] = -heso[i2];
        i2--;
    }
    return polynomial(size, arr);
}

long double polynomial::operator () (double x) {
    long double ans = 0, curX = 1;
    for (int i = n; i >= 0; i--) {
        ans += heso[i] * curX;
        curX *= x;
    }
    return ans;
}

double & polynomial::operator [] (int pos) {
    pos = min(n, max(pos, 0));
    return heso[pos];
}

const polynomial & polynomial::operator = (const polynomial & p) {
    n = p.n;
    delete [] heso;
    heso = new double[n + 1];
    for (int i = 0; i <= n; i++)
        heso[i] = p.heso[i];
    return *this;
}

istream & operator >> (istream & in, polynomial & p) {
    int n;
    in >> n;
    double *arr = new double[n + 1];
    for (int i = 0; i <= n; i++)
        in >> arr[i];
    p = polynomial(n, arr);
    return in;
}

ostream & operator << (ostream & out, const polynomial & p) {
    for (int i = p.n; i > 0; i--)
        out << p.heso[p.n - i] << "x^" << i << '+';
    out << p.heso[p.n];
    return out;
}

#endif