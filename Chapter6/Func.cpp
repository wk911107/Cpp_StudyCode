#include <iostream>

using namespace std;


void Test(int *p) {
    *p = 33;
}

void Test2(int *p) {
    p = 0;
}

int main() {
    int a = 12;
    int* p = &a;

    cout << "p = " << p << endl;
    
    Test(p);
    cout << "a = " << a << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    return 0;
}