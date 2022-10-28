#ifndef list_h
#define list_h

#include <iostream>
#include "book.h"
using namespace std;

class list
{
private:
    int size;
    book *data;
public:
    list();
    list(const list &);
    ~list();
    void showList() const;
    void add(const book &, int);
    void del(int);
    int lowerBoundYear(int, bool cmp(int, int)) const;
    void sortByYear(bool cmp(int, int));
    book & operator [] (int);
};


#endif