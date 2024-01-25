#include <iostream>

using namespace std;

int main() {
    int i = 33;

    //引用不是一个对象,只是相当于对i变量的一个别名
    int& refi = i;

    refi = 344;
    cout << "i = " << i << endl;
    cout << "&ref = " << &refi << endl;
    cout << "ref = " << refi << endl;
    return 0;
}