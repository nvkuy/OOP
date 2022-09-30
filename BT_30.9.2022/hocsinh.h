#include <iostream>
using namespace std;

class hocsinh {

private:
    static int cnt;
    const int msv;
    string ten;
    float van, toan;
public:
    hocsinh();
    hocsinh(string, float, float);
    hocsinh(const hocsinh &);
    ~hocsinh();
    void nhap();
    void xuat() const;
    static void cntST();
    string layTen();
    float layDiemVan();
    float layDiemToan();
    void ganTen(string &);
    void ganDiemVan(float);
    void ganDiemToan(float);
    float getGPA();
    string xeploai();
};

int id = 0;
int hocsinh::cnt = 0;

hocsinh::hocsinh():msv(id) {
    id++;
    cnt++;
}

hocsinh::hocsinh(string name, float v, float t): msv(id), ten(name), van(v), toan(t) {
    id++;
    cnt++;
}

hocsinh::hocsinh(const hocsinh &hs): msv(id), ten(hs.ten), van(hs.van), toan(hs.toan) {
    id++;
    cnt++;
} 

hocsinh::~hocsinh()
{
    cnt--;
}

void hocsinh::nhap() {
    cout << "Nhap ten: "; cin >> ten;
    cout << "Nhap diem van: "; cin >> van;
    cout << "Nhap diem toan: "; cin >> toan;
}

void hocsinh::xuat() const {
    cout << msv << ten << ' ' << van << ' ' << toan << endl;
}

void hocsinh::cntST() {
    cout << "Co " << cnt << " hoc sinh" << endl;
}

string hocsinh::layTen() {
    return ten;
}

float hocsinh::layDiemToan() {
    return toan;
}

float hocsinh::layDiemVan() {
    return van;
}

void hocsinh::ganTen(string &s) {
    ten = s;
}

void hocsinh::ganDiemToan(float t) {
    toan = t;
}

void hocsinh::ganDiemVan(float v) {
    van = v;
}

float hocsinh::getGPA() {
    return (van + toan) / 2;
}

string hocsinh::xeploai() {
    float gpa = getGPA();
    if (gpa > 8)
        return "GIOI";
    if (gpa > 7)
        return "KHA";
    if (gpa > 5)
        return "TRUNG BINH";
    return "YEU";
}