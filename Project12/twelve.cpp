#include <iostream>
using namespace std;

class People
{
public:
    void setName(string name);
    void show();

protected:
    string m_name;
};

void People::setName(string name)
{
    m_name = name;
}

void People::show()
{
    cout << m_name << endl;
}

class Stu : public People
{
public:
    using People::m_name; //将protected改为public

private:
    using People::show; //将public改为private
};

int main()
{
    People peo; //基类
    // peo.m_name;  成员 "People::m_name" (已声明 所在行数:11) 不可访问
    peo.setName("wxx");
    peo.show();
    Stu stu;
    stu.m_name = "lsj"; // protected改为public后可在对象访问
    // stu.show();   将public改为private  :函数 "People::show" (已声明 所在行数:19) 不可访问
    cout << stu.m_name << endl;
}
