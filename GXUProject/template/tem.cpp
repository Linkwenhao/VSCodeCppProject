#include <iostream>
using namespace std;

template <typename T1, typename T2>
class GXU
{
public:
    GXU(T1 A, T2 B);

public:
    int Add();

private:
    T1 m_A;
    T2 m_B;
};

template <typename T1, typename T2>
GXU<T1, T2>::GXU(T1 A, T2 B) : m_A(A), m_B(B)
{
}

template <typename T1, typename T2>
int GXU<T1, T2>::Add()
{
    return m_A + m_B;
}

int main()
{
    GXU<int, float> win(120, 140.00);
    cout << win.Add() << endl;
    GXU<int, double> *winwin = new GXU<int, double>(125, 149.00);
    cout << winwin->Add() << endl;
}