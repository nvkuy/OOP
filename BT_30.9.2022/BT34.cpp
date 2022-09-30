#include <iostream>
#include "intarr.h"

using namespace std;

bool inc(const int n1, const int n2);
bool dec(const int n1, const int n2);

int main() {

    IntArr b(4);
    b.nhap();
    b.xuat();

    int c[4] = {4, 2, 7, 1};
    IntArr a(4, c);
    a.xuat();

    cout << a.find(2) << endl;
    a.sortArr(0, 3, inc);
    a.xuat();

    cout << a.getSize() << endl;
    cout << a.getElement(0) << endl;
    a.setElement(3, 2);

    return 0;
}

bool inc(const int n1, const int n2) {
    return n1 <= n2;
}

bool dec(const int n1, const int n2) {
    return n1 >= n2;
}