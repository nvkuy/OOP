#include <bits/stdc++.h>

using namespace std;

struct student {
    double gpa, liter, math;
    string name, type;
};

istream & operator >> (istream &in, student &st) {

    cout << "Nhap ten sinh vien: ";
    in >> st.name;
    cout << "Nhap diem van sinh vien: ";
    st.liter = -1;
    while (st.liter < 0 || st.liter > 10)
        in >> st.liter;
    cout << "Nhap diem toan sinh vien: ";
    st.math = -1;
    while (st.math < 0 || st.math > 10)
        in >> st.math;
    st.gpa = (st.liter + st.math) / 2;
    if (st.gpa >= 8)
        st.type = "Gioi";
    else if (st.gpa >= 7)
        st.type = "Kha";
    else if (st.gpa >= 5)
        st.type = "Trung binh";
    else
        st.type = "Yeu";

    return in;
}

ostream & operator << (ostream &out, const student &st) {
    out << st.name << " - van: " << st.liter << " toan: " << st.math << " gpa: " << st.gpa << " => " << st.type;
    return out;
}

bool inc(const student &st1, const student &st2) {
    return st1.gpa < st2.gpa;
}

bool dec(const student &st1, const student &st2) {
    return st1.gpa > st2.gpa;
}

void merge(int l, int r, student *sl, bool cmp(const student &st1, const student &st2)) {
    student *tmp;
    tmp = new student[r - l + 1];
    int m = (l + r) / 2;
    int i1 = l, i2 = m + 1, i3 = 0;
    while (i1 <= m && i2 <= r) {
        if (cmp(sl[i1], sl[i2])) {
            tmp[i3] = sl[i1];
            i1++;
        } else {
            tmp[i3] = sl[i2];
            i2++;
        }
        i3++;
    }
    for (int i = i1; i <= m; i++) {
        tmp[i3] = sl[i];
        i3++;
    }
    for (int i = i2; i <= r; i++) {
        tmp[i3] = sl[i];
        i3++;
    }
    for (int i = l; i <= r; i++)
        sl[i] = tmp[i - l];
}

void mergeSort(int l, int r, student *sl, bool cmp(const student &st1, const student &st2) = dec) {
    if (l >= r)
        return;
    int m = (l + r) / 2;
    mergeSort(l, m, sl, cmp);
    mergeSort(m + 1, r, sl, cmp);
    merge(l, r, sl, cmp);
}

int main()
{

    cout << setprecision(2) << fixed;

    int n;
    student *sl;

    cout << "Nhap so luong sinh vien: ";

    cin >> n;
    sl = new student[n];
    for (int i = 0; i < n; i++)
        cin >> sl[i];

    mergeSort(0, n - 1, sl);
    cout << "Danh sach sinh vien theo gpa:" << endl;
    for (int i = 0; i < n; i++)
        cout << sl[i] << endl;

    return 0;
}
