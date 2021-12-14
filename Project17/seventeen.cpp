#include <iostream>
using namespace std;

void compare();

class A
{
public:
    A(int a);
    void show();

private:
    int m_a;
};

A::A(int a) : m_a(a)
{
}
void A::show()
{
    cout << "m_a=" << m_a << ends;
}

class B : public A
{
private:
    int m_b;

public:
    B(int a, int b);
    void show();
};

B::B(int a, int b) : A(a), m_b(b)
{
}

void B::show()
{
    A::show();
    cout << " m_b=" << m_b << endl;
}

class C
{
public:
    C(int c);
    void show();

protected:
    int m_c;
};

C::C(int c) : m_c(c)
{
}
void C::show()
{
    cout << "m_c=" << m_c << endl;
}

class D : public B, public C
{
public:
    D(int a, int b, int c, int d);
    void show();

private:
    int m_d;
};
D::D(int a, int b, int c, int d) : B(a, b), C(c), m_d(d)
{
}

void D::show()
{
    B::show();
    C::show();
    cout << "m_d=" << m_d << endl;
}

int main()
{
    A *pa = new A(1);
    B *pb = new B(2, 20);
    C *pc = new C(3);
    D *pd = new D(4, 40, 400, 4000);

    pa = pd;
    pa->show();
    cout << endl;
    pb = pd;
    pb->show();
    pc = pd;
    pc->show();

    cout << "-----------------------" << endl;
    cout << "pa=" << pa << endl;
    cout << "pb=" << pb << endl;
    cout << "pc=" << pc << endl;
    cout << "pd=" << pd << endl;

    cout << "-----------引用-----------" << endl;

    D d(4, 40, 400, 4000);

    A &ra = d;
    B &rb = d;
    C &rc = d;

    ra.show();
    cout << endl;
    rb.show();
    rc.show();
}

void compare()
{
    A a(10);
    B b(20, 30);
    //派生赋值基类前
    a.show();
    cout << endl;
    b.show();
    cout << "_______a=b_______" << endl;
    //赋值
    a = b;
    a.show();
    cout << endl;
    b.show();
}