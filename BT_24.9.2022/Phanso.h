#ifndef Phanso_h
#define Phanso_h

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

class Phanso {
    private:
        int tu, mau;
    public:
        Phanso(): tu(0), mau(1) {}
        Phanso(int t, int m = 1): tu(t), mau(m) {}
        Phanso(const Phanso &ps): tu(ps.tu), mau(ps.mau) {}
        int layTu() const {
            return tu;
        }
        int layMau() const {
            return mau;
        }
        void ganTu(int x) {
            tu = x;
        }
        void ganMau(int x) {
            mau = x;
        }
        void nghichdao() {
            if (tu == 0)
                return;
            swap(tu, mau);
        }
        void rutgon() {
            int tmp = gcd(tu, mau);
            tu /= tmp;
            mau /= tmp;
        }
};

istream & operator >> (istream &in, Phanso &ps) {
    string tmp, t1, t2;
    in >> tmp;
    bool t3 = true;
    for (int i = 0; i < tmp.length(); i++) {
        if (tmp[i] == '/') {
            t3 = false;
                continue;
        }
        if (t3)
            t1.push_back(tmp[i]);
        else
            t2.push_back(tmp[i]);
        }
    if (t2.size() == 0)
        t2 = "1";
        ps = Phanso(stoi(t1), stoi(t2));
    if (ps.layMau() == 0)
        ps = Phanso(1e9, 1);
    return in;
}
ostream & operator << (ostream &out, const Phanso &ps) {
    out << ps.layTu();
    if (ps.layMau() > 1)
        out << '/' << ps.layMau();
    return out;
}

Phanso add(const Phanso &ps1, const Phanso &ps2) {
    int tmp = lcm(ps1.layMau(), ps2.layMau());
    Phanso ans(ps1.layTu() * (tmp / ps1.layMau()) + ps2.layTu() * (tmp / ps2.layMau()), tmp);
    if (ans.layMau() == 0)
        ans.ganTu(1e9), ans.ganMau(1);
    return ans;
}
Phanso sub(const Phanso &ps1, const Phanso &ps2) {
    Phanso tmp(ps2);
    tmp.ganTu(-tmp.layTu());
    return add(ps1, tmp);
}
Phanso mul(const Phanso &ps1, const Phanso &ps2) {
    return Phanso(ps1.layTu() * ps2.layTu(), ps1.layMau() * ps2.layMau());
}
Phanso div(const Phanso &ps1, const Phanso &ps2) {
    Phanso tmp(ps2);
    tmp.nghichdao();
    return mul(ps1, tmp);
}
bool operator == (const Phanso &ps1, const Phanso &ps2) {
    int tmp = lcm(ps1.layMau(), ps2.layMau());
    return ps1.layTu()* (tmp / ps1.layMau()) == ps2.layTu()* (tmp / ps2.layMau());
}
bool operator > (const Phanso &ps1, const Phanso &ps2) {
    int tmp = lcm(ps1.layMau(), ps2.layMau());
    return ps1.layTu()* (tmp / ps1.layMau()) > ps2.layTu()* (tmp / ps2.layMau());
}
bool operator < (const Phanso &ps1, const Phanso &ps2) {
    int tmp = lcm(ps1.layMau(), ps2.layMau());
    return ps1.layTu()* (tmp / ps1.layMau()) < ps2.layTu()* (tmp / ps2.layMau());
}

#endif