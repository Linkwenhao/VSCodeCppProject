#include <iostream>
using namespace std;
//基类People
class People
{
public:
    void show();
    void more(string name);

protected:
    string m_name;
    int m_age;
};
void People::show()
{
    cout << "嗨，大家好，我叫" << m_name << "，今年" << m_age << "岁" << endl;
}

void People::more(string name)
{
    cout << "more(string name) = " << name << endl;
}
//派生类Student
class Student : public People
{
public:
    Student(string name, int age, float score);

public:
    void show();      //遮蔽基类的show()
    void more(int a); //遮蔽基类的more(),不会构成重载
private:
    float m_score;
};
Student::Student(string name, int age, float score)
{
    m_name = name;
    m_age = age;
    m_score = score;
}
void Student::show()
{
    cout << m_name << "的年龄是" << m_age << "，成绩是" << m_score << endl;
}
void Student::more(int a)
{
    cout << "more(int a) = " << a << endl;
}

int main()
{
    Student stu("小明", 16, 90.5);
    //使用的是派生类新增的成员函数，而不是从基类继承的，不会重载
    stu.show();
    stu.more(10);
    // stu.more("wxx");  //ERROR

    //使用的是从基类继承来的成员函数
    stu.People::show();
    stu.People::more("WXX");
    return 0;
}