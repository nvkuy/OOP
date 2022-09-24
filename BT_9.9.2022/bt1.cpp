#include <iostream>

using namespace std;

void readArr(int &n, int *&a);
void showArr(int n, const int *a);

bool inc(const int n1, const int n2);
bool dec(const int n1, const int n2);

void mergeSort(int l, int r, int *a, bool cmp(int n1, int n2) = inc);
void qsort(int low, int high, int *a, bool cmp(int n1, int n2) = inc);
void heapSort(int l, int r, int *arr, bool cmp(int n1, int n2) = inc);
void sortArr(int le, int ri, int *a, bool cmp(int n1, int n2) = inc, void mode(int le, int ri, int *a, bool cmp(int n1, int n2)) = mergeSort);

int linSearch(int l, int r, int *a, int val, bool cmp(int n1, int n2) = inc);
int binSearch(int l, int r, int *a, int val, bool cmp(int n1, int n2) = inc);
int ipSearch(int l, int r, int *a, int val, bool cmp(int n1, int n2) = inc);
int search(int l, int r, int *a, int val, int mode(int l, int r, int *a, int val, bool cmp(int n1, int n2)) = linSearch, bool cmp(int n1, int n2) = inc);

int main()
{

    int n, *a;
    readArr(n, a);
    sortArr(0, n - 1, a, dec, heapSort);
    showArr(n, a);
    int val;
    cout << "Nhap gia tri can tim kiem: ";
    cin >> val;
    cout << search(0, n - 1, a, val, ipSearch, dec);

    return 0;
}

void readArr(int &n, int *&a) {
    cout << "Nhap so phan tu n = ";
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap a[" << i << "] = ";
        cin >> a[i];
    }
}

void showArr(int n, const int *a) {
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}

bool inc(const int n1, const int n2) {
    return n1 <= n2;
}

bool dec(const int n1, const int n2) {
    return n1 >= n2;
}

void merge(int l, int r, int *a, bool cmp(int n1, int n2)) {
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

void mergeSort(int l, int r, int *a, bool cmp(int n1, int n2)) {
    if (l >= r)
        return;
    int m = (l + r) / 2;
    mergeSort(l, m, a, cmp);
    mergeSort(m + 1, r, a, cmp);
    merge(l, r, a, cmp);
}

int partition(int arr[], int low, int high, bool cmp(int n1, int n2))
{
    int pivot = arr[high];
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && cmp(arr[left], pivot)) left++;
        while(right >= left && cmp(pivot, arr[right])) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}

void qsort(int low, int high, int *a, bool cmp(int n1, int n2)) {
    if (low < high)
    {
        int pi = partition(a, low, high, cmp);
        qsort(low, pi - 1, a, cmp);
        qsort(pi + 1, high, a, cmp);
    }
}

void heapify(int l, int r, int *arr, int i, bool cmp(int n1, int n2))
{
    int largest = i;
    int left = 2 * (i - l) + 1 + l;
    int right = 2 * (i - l) + 2 + l;
    if (left <= r && cmp(arr[largest], arr[left]))
        largest = left;
    if (right <= r && cmp(arr[largest], arr[right]))
        largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(l, r, arr, largest, cmp);
    }
}

void heapSort(int l, int r, int *arr, bool cmp(int n1, int n2))
{
    for (int i = (l + r - 1) / 2; i >= 0; i--)
        heapify(l, r, arr, i, cmp);
    for (int i = r; i >= l; i--) {
        swap(arr[l], arr[i]);
        heapify(l, i - 1, arr, l, cmp);
    }
}

void sortArr(int le, int ri, int *a, bool cmp(int n1, int n2), void mode(int le, int ri, int *a, bool cmp(int n1, int n2))) {
    mode(le, ri, a, cmp);
}

int linSearch(int l, int r, int *a, int val, bool cmp(int n1, int n2)) {
    for (int i = l; i <= r; i++)
        if (a[i] == val)
            return i;
    return -1;
}

int binSearch(int l, int r, int *a, int val, bool cmp(int n1, int n2)) {
    int ll = l, rr = r, mm;
    while (ll <= rr) {
        mm = (ll + rr) / 2;
        if (a[mm] == val)
            return mm;
        if (cmp(a[mm], val))
            ll = mm + 1;
        else
            rr = mm - 1;
    }
    return -1;
}

int ipSearch(int l, int r, int *a, int val, bool cmp(int n1, int n2)) {
    int ll = l, rr = r, mm;
    while (ll <= rr && cmp(a[ll], val) && cmp(val, a[rr])) {
        double val1 = (double)(val - a[ll]) / (a[rr] - a[ll]);
        int val2 = (rr - ll);
        mm = ll + (val1 * val2);
        if (a[mm] == val)
            return mm;
        if (cmp(a[mm], val))
            ll = mm + 1;
        else
            rr = mm - 1;
    }
    return -1;
}

int search(int l, int r, int *a, int val, int mode(int l, int r, int *a, int val, bool cmp(int n1, int n2)), bool cmp(int n1, int n2)) {
    return mode(l, r, a, val, cmp);
}
