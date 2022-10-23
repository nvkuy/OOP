#ifndef vector_h
#define vector_h

#include <iostream>
using namespace std;

class vector {
    private:
        int n;
        double *data;
    public:
        vector(int = 0, double * = new double);
        vector(const vector &);
        ~vector();
        friend vector operator + (vector, vector);
        friend vector operator - (vector, vector);
        friend double operator * (vector, vector);
        const vector & operator = (vector);
        double & operator [] (int i);
        friend istream & operator >> (istream &, vector &);
        friend ostream & operator << (ostream &, const vector &);
};

istream & operator >> (istream & in, vector & v) {
    in >> v.n;
    v.data = new double[v.n];
    for (int i = 0; i < v.n; i++)
        in >> v.data[i];
    return in;
}

ostream & operator << (ostream & out, const vector & v) {
    for (int i = 0; i < v.n; i++)
        out << v.data[i] << ' ';
}

const vector & vector::operator = (vector v) {
    delete [] data;
    n = v.n;
    data = new double[v.n];
    for (int i = 0; i < n; i++)
        data[i] = v.data[i];
    return *this;
}

double & vector::operator [] (int i) {
    return data[i];
}

vector operator + (vector v1, vector v2) {
    double *tmp = new double[v1.n];
    for (int i = 0; i < v1.n; i++)
        tmp[i] = v1.data[i] + v2.data[i];
    return vector(v1.n, tmp);
}

vector operator - (vector v1, vector v2) {
    double *tmp = new double[v1.n];
    for (int i = 0; i < v1.n; i++)
        tmp[i] = v1.data[i] + v2.data[i];
    return vector(v1.n, tmp);
}

double operator * (vector v1, vector v2) {
    double ans = 0;
    for (int i = 0; i < v1.n; i++)
        ans += (v1.data[i] * v2.data[i]);
    return ans;
}

vector::vector(int nn, double *cor) {
    n = nn;
    data = new double[n];
    for (int i = 0; i < n; i++)
        data[i] = cor[i];
}

vector::vector(const vector &a) {
    n = a.n;
    data = new double[n];
    for (int i = 0; i < n; i++)
        data[i] = a.data[i];
}

vector::~vector() {
    delete [] data;
}

#endif