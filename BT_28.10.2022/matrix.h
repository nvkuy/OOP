#ifndef matrix_h
#define matrix_h

#include<iostream>
using namespace std;

class matrix
{
private:
    int n;
    double **mat;
public:
    matrix();
    matrix(const matrix &);
    matrix(int, double **);
    ~matrix();
    matrix operator + (const matrix &);
    matrix operator - (const matrix &);
    matrix operator * (const matrix &);
    double & operator () (int, int);
    const matrix & operator = (const matrix &);
    friend istream & operator >> (istream &, matrix &);
    friend ostream & operator << (ostream &, const matrix &);
};

matrix::matrix() {
    n = 0;
    mat = new double * [1];
    mat[1] = new double[1];
}

matrix::matrix(int size, double ** arr) {
    n = size;
    mat = new double * [n];
    for (int i = 0; i < n; i++) {
        mat[i] = new double[n];
        for (int j = 0; j < n; j++)
            mat[i][j] = arr[i][j];
    }
}

matrix::matrix(const matrix & mm) {
    n = mm.n;
    mat = new double * [n];
    for (int i = 0; i < n; i++) {
        mat[i] = new double[n];
        for (int j = 0; j < n; j++)
            mat[i][j] = mm.mat[i][j];
    }
}

matrix::~matrix() {
    for (int i = 0; i < n; i++)
        delete [] mat[i];
    delete [] mat;
}

matrix matrix::operator + (const matrix & m) {
    double ** arr;
    if (n != m.n)
        return matrix(m.n, arr);
    arr = new double * [m.n];
    for (int i = 0; i < n; i++)
        arr[i] = new double[m.n];
    for (int i = 0; i < m.n; i++)
        for (int j = 0; j < m.n; j++)
            arr[i][j] = mat[i][j] + m.mat[i][j];
    return matrix(m.n, arr);
}

matrix matrix::operator - (const matrix & m) {
    double ** arr;
    if (n != m.n)
        return matrix(m.n, arr);
    arr = new double * [m.n];
    for (int i = 0; i < n; i++)
        arr[i] = new double[m.n];
    for (int i = 0; i < m.n; i++)
        for (int j = 0; j < m.n; j++)
            arr[i][j] = mat[i][j] - m.mat[i][j];
    return matrix(m.n, arr);
}

matrix matrix::operator * (const matrix & m) {
    double ** arr;
    if (n != m.n)
        return matrix(m.n, arr);
    arr = new double * [m.n];
    for (int i = 0; i < n; i++)
        arr[i] = new double[m.n];
    for (int i = 0; i < m.n; i++) {
        for (int j = 0; j < m.n; j++) {
            double tans = 0;
            for (int k = 0; k < n; k++)
                tans += (mat[i][k] * m.mat[k][j]);
            arr[i][j] = tans;
        }
    }
    return matrix(m.n, arr);
}

double & matrix::operator () (int i, int j) {
    i = min(n - 1, max(i, 0));
    j = min(n - 1, max(j, 0));
    return mat[i][j];
}

const matrix & matrix::operator = (const matrix & mm) {
    for (int i = 0; i < n; i++)
        delete [] mat[i];
    delete [] mat;
    n = mm.n;
    mat = new double * [n];
    for (int i = 0; i < n; i++) {
        mat[i] = new double[n];
        for (int j = 0; j < n; j++)
            mat[i][j] = mm.mat[i][j];
    }
    return *this;
}

istream & operator >> (istream & in, matrix & m) {
    int n;
    in >> n;
    double ** arr = new double * [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new double[n];
        for (int j = 0; j < n; j++)
            in >> arr[i][j];
    }
    m = matrix(n, arr);
    return in;
}

ostream & operator << (ostream & out, const matrix & m) {
    for (int i = 0; i < m.n; i++) {
        for (int j = 0; j < m.n; j++) {
            cout << m.mat[i][j] << ' ';
        }
        cout << endl;
    }
    return out;
}

#endif