#include "book.h"
#include "list.h"
#include <iostream>
using namespace std;

bool asc_year(int y1, int y2) {
    return y1 < y2;
}

bool dec_year(int y1, int y2) {
    return y1 > y2;
}

list::list() {
    size = 0;
}
list::list(const list & l) {
    size = l.size;
    data = new book[size];
    for (int i = 0; i < size; i++)
        data[i] = l.data[i];
}
list::~list() {
    // delete data;
}
void list::showList() const {
    for (int i = 0; i < size; i++)
        cout << data[i] << endl;
}
void list::add(const book & b, int pos) {
    if (b.getNum() <= 0)
        return;
    for (int i = 0; i < size; i++) {
        if (b.getId() == data[i].getId()) {
            data[i].setNum(data[i].getNum() + b.getNum());
            return;
        }
    }
    if (pos >= size)
        return;
    if (pos < 0)
        return;
    book *tmp = new book[size];
    for (int i = 0; i < size; i++)
        tmp[i] = data[i];
    delete [] data;
    data = new book[size + 1];
    for (int i = 0; i < pos; i++)
        data[i] = tmp[i];
    data[pos] = b;
    for (int i = pos + 1; i <= size; i++)
        data[i] = tmp[i - 1];
    size++;
    delete [] tmp;
}
void list::del(int pos) {
    if (pos >= size)
        return;
    if (pos < 0)
        return;
    book *tmp = new book[size - 1];
    for (int i = 0; i < pos; i++)
        tmp[i] = data[i];
    for (int i = pos + 1; i < size; i++)
        tmp[i - 1] = data[i];
    size--;
    delete [] data;
    data = new book[size];
    for (int i = 0; i < size; i++)
        data[i] = tmp[i];
    delete [] tmp;
}
int list::lowerBoundYear(int year, bool cmp(int, int)) const {
    int l = 0, r = size - 1, m;
    while (l < r) {
        m = (l + r) / 2;
        if (cmp(data[m].getYear(), year))
            l = m + 1;
        else
            r = m;
    }
    return r;
}
void list::sortByYear(bool cmp(int, int)) {
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            book temp = data[i];
            int j;            
            for (j = i; j >= gap && !cmp(data[j - gap].getYear(), temp.getYear()); j -= gap)
                data[j] = data[j - gap];
            data[j] = temp;
        }
    }
}
book & list::operator [] (int pos) {
    pos = min(pos, size - 1);
    pos = max(pos, 0);
    return data[pos];
}