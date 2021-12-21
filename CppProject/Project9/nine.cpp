#include <iostream>
using namespace std;

double volume(const double &len, const double &width, const double &hei)
{
    return len * width * 2 + len * hei * 2 + width * hei * 2;
}
int main()
{
    int a = 10, b = 20, c = 20;
    double v1 = volume(a, b, c);
    double v2 = volume(10, 20, 30);
    double v3 = volume(89.4, 32.7, 19);
    double v4 = volume(a + 12.5, b + 23.4, 16.78);
    double v5 = volume(a + b, a + c, b + c);
    cout << a << "," << b << "," << c << endl;  //不会修改引用的值
    printf("%lf, %lf, %lf, %lf, %lf\n", v1, v2, v3, v4, v5);
    return 0;
}