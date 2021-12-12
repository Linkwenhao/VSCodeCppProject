#include <iostream>
using namespace std;

void ref();
void swap1(int a, int b);
void swap2(int *p1, int *p2);
void swap3(int &r1, int &r2);
int &plus10(int &r);

int main()
{
    int a = 350, b = 270;
    cout << a << "," << b << endl;
    swap1(a, b);
    cout << a << "," << b << endl;
    swap2(&a, &b);
    cout << a << "," << b << endl;
    swap3(a, b);
    cout << a << "," << b << endl;
    cout << "plus10(a)=" << plus10(a) << endl;
    cout << "a = " << a << endl;
}

//直接传递参数内容
void swap1(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

//传递指针
void swap2(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

//按照引用传参
void swap3(int &r1, int &r2)
{
    int temp = r1;
    r1 = r2;
    r2 = temp;
}

int &plus10(int &r)
{
    r += 10;
    return r;
}

void ref()
{
    int a = 99;
    int &r = a; //引用reference
    cout << a << "," << r << endl;
    cout << &a << "," << &r << endl;
    r = 100; //修改引用，被引用的也修改了
    cout << a << "," << r << endl;
    const int &rr = a; //常引用 ，不可通过该引用修改 被引用的值
    cout << a << "," << rr << endl;
}
