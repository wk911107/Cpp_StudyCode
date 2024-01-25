#include <iostream>

using namespace std;

int main() {

    int iVal = 55;

    int* p = &iVal;

    //p为指针,指向iVal的地址
    cout << "p = " << p << endl;
    //*p 解引用,表示iVal的值
    cout << "*p = " << *p << endl;
    cout << "&p = " << &p << endl;

    return 0;
}