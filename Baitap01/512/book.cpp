#include "book.h"
#include <iostream>
using namespace std;

bool isValidId(const string &id) {
    if (id.length() != 9)
        return false;
    for (int i = 0; i < 5; i++)
        if (id[i] < '1' || id[i] > '5')
            return false;
    for (int i = 5; i < 9; i++)
        if (id[i] < '0' || id[i] > '9')
            return false;
    return true;
}
book::book() {}
book::book(const string & idx, const string & namex, int yearx, int numx, bool statusx) {
    if (!isValidId(idx) || numx <= 0)
        return;
    id = idx, name = namex;
    year = yearx, num = numx;
    status = statusx;
}

string book::getId() const {
    return id;
}
string book::getName() const {
    return name;
}
int book::getYear() const {
    return year;
}
int book::getNum() const {
    return num;
}
bool book::getStatus() const {
    return status;
}

void book::setId(const string & idx) {
    if (!isValidId(idx))
        return;
    id = idx;
}
void book::setName(const string & namex) {
    name = namex;
}
void book::setYear(int yearx) {
    year = yearx;
}
void book::setNum(int numx) {
    num = numx;
}
void book::setStatus(bool statusx) {
    status = statusx;
}

istream & operator >> (istream & in, book & b) {
    string t1, t2;
    int t3, t4;
    bool t5;
    while (!isValidId(t1)) {
        cout << "Nhap ma sach:" << endl;
        in >> t1;
    }
    in.ignore();
    cout << "Nhap ten sach:" << endl;
    getline(in, t2);
    cout << "Nhap nam xuat ban:" << endl;
    in >> t3;
    cout << "Nhap so luong:" << endl;
    in >> t4;
    cout << "Nhap trang thai:" << endl;
    in >> t5;
    b = book(t1, t2, t3, t4, t5);
    return in;
}
ostream & operator << (ostream & out, const book & b) {
    out << b.getId() << '|' << b.getName() << '|' << b.getYear() << '|' << b.getNum() << '|' << b.getStatus();
    return out;
}