#include"matrix.h"
#include<iostream>
using namespace std;

int main() {

    // freopen("input.txt", "r", stdin);
    matrix m1, m2;
    cin >> m1 >> m2;
    cout << m1 + m2 << endl;
    cout << m1 * m2 << endl;

    return 0;
}