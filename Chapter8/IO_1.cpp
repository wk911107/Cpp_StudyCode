#include <iostream>
#include <stdexcept>

using namespace std;

istream& f(istream& in) {
    int v;
    while (in >> v, !in.eof())
    {
       if (in.bad())
       {
           cout << "IO流错误" << endl;
           break;
       }

       if (in.fail())
       {
           cerr << "数据错误,请重试:" << endl;
           in.clear();
           in.ignore(100, '\n');
           continue;
       }

       cout << "获取的值: " << v << endl;
    }

    in.clear();

    return in;

}

int main() {
    cout << "请输入一些整数,Ctrl+Z退出" << endl;
    f(cin);
    return 0;
}