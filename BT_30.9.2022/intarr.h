#ifndef intarr_h
#define intarr_h

#include <iostream>
using namespace std;

class IntArr {

private:
    int size;
    int *data;
public:
    void merge(int l, int r, int *a, bool cmp(int n1, int n2));
    void mergeSort(int l, int r, int *a, bool cmp(int n1, int n2));
    IntArr();
    IntArr(int);
    IntArr(int, int *);
    IntArr(const IntArr &);
    ~IntArr();
    void nhap();
    void xuat();
    int getSize() const;
    int getElement(int) const;
    void setElement(int, int);
    int find(int);
    void sortArr(int, int, bool cmp(int n1, int n2));
};

int IntArr::getElement(int p) const {
    return data[p];
}

IntArr::IntArr() {
    size = 0;
}
IntArr::IntArr(int n) {
    data = new int[n];
    size = n;
    for (int i = 0; i < n; i++)
        data[i] = 0;
}

IntArr::IntArr(int n, int arr[]) {
    size = n;
    data = new int[n];
    for (int i = 0; i < n; i++)
        data[i] = arr[i];
}

IntArr::IntArr(const IntArr &arr) {
    size = arr.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = arr.getElement(i);
}

IntArr::~IntArr() {
    delete data;
}

void IntArr::nhap() {
    cin >> size;
    data = new int[size];
    for (int i = 0; i < size; i++)
        cin >> data[i];
}

void IntArr::xuat() {
    for (int i = 0; i < size; i++)
        cout << data[i] << ' ';
    cout << endl;
}

int IntArr::getSize() const {
    return size;
}

void IntArr::setElement(int p, int val) {
    data[p] = val;
}

int IntArr::find(int val) {
    for (int i = 0; i < size; i++)
        if (data[i] == val)
            return i;
    return -1;
}

void IntArr::sortArr(int l, int r, bool cmp(int n1, int n2)) {
    mergeSort(l, r, data, cmp);
}

void IntArr::merge(int l, int r, int *a, bool cmp(int n1, int n2)) {
    int *tmp;
    tmp = new int[r - l + 1];
    int m = (l + r) / 2;
    int i1 = l, i2 = m + 1, i3 = 0;
    while (i1 <= m && i2 <= r) {
        if (cmp(a[i1], a[i2])) {
            tmp[i3] = a[i1];
            i1++;
        } else {
            tmp[i3] = a[i2];
            i2++;
        }
        i3++;
    }
    for (int i = i1; i <= m; i++) {
        tmp[i3] = a[i];
        i3++;
    }
    for (int i = i2; i <= r; i++) {
        tmp[i3] = a[i];
        i3++;
    }
    for (int i = l; i <= r; i++)
        a[i] = tmp[i - l];
}

void IntArr::mergeSort(int l, int r, int *a, bool cmp(int n1, int n2)) {
    if (l >= r)
        return;
    int m = (l + r) / 2;
    mergeSort(l, m, a, cmp);
    mergeSort(m + 1, r, a, cmp);
    merge(l, r, a, cmp);
}

#endif