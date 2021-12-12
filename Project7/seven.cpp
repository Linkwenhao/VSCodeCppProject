#include <iostream>
using namespace std;

int main()
{
    string str = "gxuctf";
    cout << "before insert =" << str << endl;
    str.insert(0, "welcome ");
    cout << "after insert =" << str << endl;
    str.insert(7, " to");
    cout << "after insert =" << str << endl;
    // welcome to gxuctf
    int index = str.find("welcome", 0);
    cout << "查找字符串的位置" << index << endl;
    string s2 = str.substr(0, 7);
    cout << "str.substr =" << s2 << endl;
    str.erase(0, 8);
    cout << "after erase =" << str << endl;
}