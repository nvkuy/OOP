#ifndef book_h
#define book_h

#include <iostream>
using namespace std;

class book
{
private:
    string id, name;
    int year, num;
    bool status;
public:
    book();
    book(const string &, const string &, int, int, bool);

    string getId() const;
    string getName() const;
    int getYear() const;
    int getNum() const;
    bool getStatus() const;

    void setId(const string &);
    void setName(const string &);
    void setYear(int);
    void setNum(int);
    void setStatus(bool);

    friend istream & operator >> (istream &, book &);
    friend ostream & operator << (ostream &, const book &);

};


#endif