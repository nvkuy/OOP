#include "set.h"
#include <iostream>

using namespace std;

int main() {

    set s1;
    s1 + 3; s1 + 2; s1 + 4;
    set s2(s1);
    s2 + 1; s2 + 5;
    s1 + 7;
    cout << "set 1: ";
    cout << s1 << endl;
    cout << "set 2: ";
    cout << s2 << endl;
    cout << "set 1 + set 2: ";
    cout << s1 + s2 << endl;
    cout << "set 1 - set 2: ";
    cout << s1 - s2 << endl;
    cout << "set 1 * set 2: ";
    cout << s1 * s2 << endl;
    cout << "Assign set 2 to set 1: ";
    s1 = s2;
    cout << s1 << endl;

    return 0;
}