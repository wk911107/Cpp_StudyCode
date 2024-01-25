#include <iostream>

using namespace std;

int main() {

    int iVal = 33;

    int& iRef = iVal;

    int* p = &iVal;

    *p = iVal;

    *p = 333;
    cout << "iVal = " << iVal << endl;
    int& iRef2 = *p;
    iRef2 = 24234;
    cout << "iVal = " << *p << endl;


    return 0;
}