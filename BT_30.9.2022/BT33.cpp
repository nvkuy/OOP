#include <iostream>
#include "hocsinh.h"

using namespace std;

int main() {

    hocsinh hs1("ABC", 9, 6);
    cout << "HOC SINH 1: "; hs1.xuat();
    hs1.cntST();
    hocsinh hs2(hs1);
    cout << "HOC SINH 2 COPY TU HOC SINH 1: "; hs2.xuat();
    hs2.cntST();
    hocsinh hs3;
    hocsinh::cntST();
    hs3.nhap();

    hs1.xuat();
    hs2.xuat();
    hs3.xuat();    

    cout << "GAN DIEM TOAN HOC SINH = 10: ";
    hs2.ganDiemToan(10);
    hs2.xuat();

    cout << "DIEM TRUNG BINH HOC SINH 3: ";
    cout << hs3.getGPA() << endl;
    cout << "XEP LOAI HOC SINH 3: ";
    cout << hs1.xeploai() << endl;
    
    return 0;
}