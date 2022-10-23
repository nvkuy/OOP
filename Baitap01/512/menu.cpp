#include <iostream>
#include "list.cpp"
#include "book.cpp"
using namespace std;

int main() {
    list ml;
    while (true) {
        cout << "1. Show list" << endl;
        cout << "2. Add list" << endl;
        cout << "3. Del list" << endl;
        cout << "4. Find list" << endl;
        cout << "5. Sort list" << endl;
        cout << "Exit" << endl;
        int type;
        cin >> type;
        if (type == 1) {
            ml.showList();
        } else if (type == 2) {
            book tmp;
            int pos;
            cout << "Nhap thong tin sach:" << endl;
            cin >> tmp;
            cout << "Nhap vi tri them neu co the:" << endl;
            cin >> pos;
            ml.add(tmp, pos);
        } else if (type == 3) {
            int pos;
            cout << "Nhap vi tri xoa:" << endl;
            cin >> pos;
            ml.del(pos);
        } else if (type == 4) {
            int num, pos;
            cout << "Nhap nam can tim kiem:" << endl;
            cin >> num;
            pos = ml.lowerBoundYear(num, dec_year);
            if (ml[pos].getYear() != num) {
                cout << "Khong tim thay" << endl;
                continue;
            }
            cout << ml[pos] << endl;
        } else if (type == 5) {
            ml.sortByYear(dec_year);
        } else
            break;
    }
}