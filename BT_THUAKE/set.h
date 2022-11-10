#ifndef set_h
#define set_h

#include <iostream>
#include "linked_list.h"
using namespace std;

class set : public linked_list
{
public:
    set();
    set(int, const int *);
    set(const set &);
    // ~set();
    void operator + (int);
    set operator + (const set &);
    void operator - (int);
    set operator - (const set &);
    set operator * (const set &);
    int operator () (int);
    int & operator [] (int);
};

int set::operator () (int num) {
    Node *cur = head;
    for (int i = 0; i < n; i++) {
        if (cur->getData() == num)
            return i;
        cur = cur->nextNode();
    }
    return -1;
}

set::set(): linked_list() {}

set::set(int n, const int * arr): linked_list(n, arr) {}

set::set(const set &s): linked_list(s) {} 

void set::operator + (int num) {
    if ((*this)(num) == -1)
        this->ins(num);
}

set set::operator + (const set &s) {
    set tmp;
    Node *cur = head;
    for (int i = 0; i < n; i++) {
        tmp + cur->getData();
        cur = cur->nextNode();
    }
    cur = s.head;
    for (int i = 0; i < s.n; i++) {
        tmp + cur->getData();
        cur = cur->nextNode();
    }
    return tmp;
}

void set::operator - (int num) {
    int pos = (*this)(num);
    if (pos != -1)
        this->del(pos);
}

set set::operator - (const set &s) {
    set tmp(*this);
    Node *cur = s.head;
    for (int i = 0; i < s.n; i++) {
        tmp - cur->getData();
        cur = cur->nextNode();
    }
    return tmp;
}

set set::operator * (const set &s) {
    set tmp;
    Node *cur = s.head;
    for (int i = 0; i < s.n; i++) {
        if ((*this)(cur->getData()) != -1)
            tmp.ins(cur->getData());
        cur = cur->nextNode();
    }
    return tmp;
}

int & set::operator [] (int pos) {
    Node *cur = head;
    for (int i = 0; i < pos; i++)
        cur = cur->nextNode();
    return cur->getData();
}

#endif