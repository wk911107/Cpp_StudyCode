#include <iostream>

using namespace std;

int main() {
    string nums[] = { "one", "two", "three" };
    //numPtr,numPtr2都是指向nums的第一个元素的地址
    string* numPtr = nums;
    string* numPtr2 = &nums[0];

    int intArr[] = { 1,2,3,4,5,6,7,8,9,10 };

    int* firstItem = begin(intArr);
    int* lastItem = end(intArr);

    cout << "First Item Address:" << firstItem << endl;
    cout << "First Item:" << *firstItem << endl;
    cout << "Last Item Address:" << --lastItem << endl;
    cout << "Last Item:" << *lastItem << endl;

    return 0;
}