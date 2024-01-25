#include <iostream>

using namespace std;

int main() {
    int iVal = 56;

    int* ptr = &iVal;

    int** pptr = &ptr;

    cout << "Thevalue ofival \n"
        << "Thevalue ofival"<< &iVal <<" \n"
        << "direct value:" << iVal << "\n"
        << "ptr value:" << ptr << "\n"
        << "indirect value:" << *ptr << "\n"
        << "*pptr value:" << *pptr << "\n"
        << "doubly indirect value:" << **pptr << endl;

    int jVal = 33;
    int* jPtr;
    int*& r = jPtr;

    r = &jVal;

    
    return 0;

}