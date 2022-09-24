#include <iostream>
#include "Phanso.h"

using namespace std;

int main() {

    Phanso p1, p2;
    cin >> p1 >> p2;
    cout << "p1=" << p1 << " p2=" << p2 << endl;
    p1.nghichdao();
    cout << "nghich dao p1=";
    cout << p1 << endl;
    cout << "tu p2=" << p2.layTu() << ' ' << "mau p2=" << p2.layMau() << endl;
    p1.ganTu(2), p1.ganMau(4);
    cout << "p1=" << p1 << " rut gon thanh ";
    p1.rutgon();
    cout << "p1=" << p1 << endl;
    cout << "p1+p2=" << add(p1, p2) << endl;
    cout << "p1-p2=" << sub(p1, p2) << endl;
    cout << "p1*p2=" << mul(p1, p2) << endl;
    cout << "p1/p2=" << div(p1, p2) << endl;
    cout << (p1 < p2 ? "p1 be hon p2" : "p1 khong be hon p2");

    return 0;
}