#include <iostream>
using namespace std;

//声明与定义模版类
template <typename T1, typename T2>
class Point
{
public:
    Point(T1 x, T2 y);

public:
    void show();

private:
    T1 m_x;
    T2 m_y;
};

template <typename T1, typename T2>
Point<T1, T2>::Point(T1 x, T2 y) : m_x(x), m_y(y)
{
}

template <typename T1, typename T2>
void Point<T1, T2>::show()
{
    cout << m_x << "," << m_y << endl;
}

//声明与定义模版函数
template <typename T>
void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

//声明模版函数
template <class T>
T max(T a, T b, T c);

int main()
{
    Point<int, int> p1(10, 20);
    p1.show();
    Point<const char *, const char *> p2("x坐标", "y坐标");
    p2.show();
    Point<double, double> *p3 = new Point<double,double>(10.25, 50.21);
    p3->show();

    {
        int a = 10, b = 20;
        Swap(a, b);
        cout << "swap(10,20) = " << a << "," << b << endl;
    }
    {
        float a = 10.15, b = 30.25;
        Swap(a, b);
        cout << "swap(10.15,30.25) = " << a << "," << b << endl;
    }

    {
        int a = 10, b = 5, c = 20;
        cout << max(a, b, c) << endl;
    }

    {
        double a = 10.24, b = 5.23, c = 10.25;
        cout << max(a, b, c) << endl;
    }
}

//定义模版
template <class T>
T max(T a, T b, T c)
{
    T max = a;
    if (b > a)
        max = b;
    if (c > b)
        max = c;
    return max;
}