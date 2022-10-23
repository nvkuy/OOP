#include "congtrinhkhoahoc.h"
#include <iostream>
using namespace std;

congtrinhkhoahoc::congtrinhkhoahoc(const string & mct, int nxb, bool qt): macongtrinh(mct), namxuatban(max(nxb, 1900)), quocte(qt) {}

string congtrinhkhoahoc::getMCT() const {
    return macongtrinh;
}

void congtrinhkhoahoc::setMCT(const string & mct) {
    macongtrinh = mct;
}

int congtrinhkhoahoc::getNXB() const {
    return namxuatban;
}

void congtrinhkhoahoc::setNXB(int nxb) {
    if (nxb >= 1900)
        namxuatban = nxb;
}

bool congtrinhkhoahoc::isQT() const {
    return quocte;
}

void congtrinhkhoahoc::setQT(bool qt) {
    quocte = qt;
}
