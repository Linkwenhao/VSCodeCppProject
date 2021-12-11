#include <iostream>
using namespace std;

class A
{
public:
    typedef string STR;

public:
    STR show(STR str);

private:
    int n;
};

A::STR A::show(STR str)
{
    cout << str << endl;
    n = 10;
    return str;
}

int main()
{
    A obj;
    obj.show("wxx");
}