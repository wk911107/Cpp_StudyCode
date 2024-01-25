#include <iostream>

using namespace std;

int main() {

    string str = "1313";
    int size = str.size();

    //字符串不能字面量相加,字面量和string 不是同一类型
    //string str2 = "12312" + "111" + str;
    string str2 = str + "12312" + "111";

    string str3 = "Hello World!!!";

    for (auto &&i : str3)
    {
        i = toupper(i);
    }

    cout << str3 << endl;


    return 0;
}