#include "linked_list.h"
#include <iostream>

using namespace std;

int main() {

    int n = 4, arr[] = {0, 1, 2, 3};
    linked_list list(n, arr);
    list.ins();
    list.ins(1);
    list.ins(2);
    list.ins(3);
    cout << list << endl;
    linked_list cp_list(list);
    cp_list.del(2);
    cout << cp_list << endl;

    return 0;
}