#ifndef congtrinhkhoahoc_h
#define congtrinhkhoahoc_h

#include <iostream>
using namespace std;

class congtrinhkhoahoc
{
private:
    string macongtrinh;
    int namxuatban;
    bool quocte;
public:
    congtrinhkhoahoc(const string &, int, bool);
    string getMCT() const;
    void setMCT(const string &);
    int getNXB() const;
    void setNXB(int);
    bool isQT() const;
    void setQT(bool);
    // friend istream & operator >> (istream &);
};

#endif