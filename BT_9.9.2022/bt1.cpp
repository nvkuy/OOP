#include <iostream>

using namespace std;

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

int main()
{

    int n, *a;
    readArr(n, a);
    showArr(n, a);

    return 0;
}
