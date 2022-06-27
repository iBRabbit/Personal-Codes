#include "iostream"
#include "stdlib.h"
#include "string"

using namespace std;

int main(int argc, char const *argv[])
{
    system("cls");
    string str;

    str.append("Hello, world!");

    cout << str << endl;
    cout << str.at(2) << endl;
    str.clear();
    cout << str << endl;

    char char1 = 'a';
    char char2 = 'b';

    string s(1, char1);
    str.append(s);
    cout << str << endl;
    string str2;
    str2.append("Hello");
    cout << str2 << endl;
    return 0;
}
