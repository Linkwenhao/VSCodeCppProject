#include <iostream>
using namespace std;

class Juvenile; //提前声明类

class Stu
{
public:
    Stu(string name, int age);

public:
    void show(Juvenile *j); //成员函数

private:
    string m_name;
    int m_age;
};

class Juvenile
{
public:
    Juvenile(string mother, string father);

public:
    friend void Stu::show(Juvenile *j); //将Stu类中的成员函数show()声明为友元函数

private:
    string m_mother;
    string m_father;
};

//实现Stu类
Stu::Stu(string name, int age) : m_age(age), m_name(name)
{
}
void Stu::show(Juvenile *j)
{
    cout << "name:  " << m_name << "  age:  " << m_age << endl;
    cout << "mom:  " << j->m_mother << " dad :" << j->m_father << endl;
}
//实现Juvenile类

Juvenile::Juvenile(string mother, string father) : m_mother(mother), m_father(father)
{
}

int main()
{
    cout << "1 or 2" << endl;
    int choice = 0;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        Stu stu("wxx", 18);
        Juvenile Juv("lsj", "lsj");
        stu.show(&Juv);
    }
    break;
    case 2:
    {
        Stu *p = new Stu("wxx", 10);
        Juvenile *j = new Juvenile("lsj", "lsj");
        p->show(j);
    }
    default:
        break;
    }
}
