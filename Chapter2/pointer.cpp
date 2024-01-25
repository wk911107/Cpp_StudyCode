#include <iostream>

using namespace std;

int main() {
    int ival = 42;

    int* p = &ival;

    double dVal = 3.0;

    //指针类型必须严格的类型匹配,不像基本类型会自动拆装箱
    //p = &dVal;

    return 0;

}