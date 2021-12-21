#include <iostream>
using namespace std;

class Student
{
public:
    Student(string name, int age, float score);
    void show();

private:
    static int m_total;

private:
    string m_name;
    int m_age;
    float m_score;
};

Student::Student(string name, int age, float score) : m_name(name), m_age(age), m_score(score)
{
    m_total++;
}
void Student::show()
{
    if (m_total != 0)
    {
        cout << "当前学生人数为" << m_total << endl;
        cout << "姓名" << m_name << "年龄" << m_age << "成绩为" << m_score << endl;
    }
}

int Student::m_total = 0;

int main()
{
    Student stu("李育琪", 22, 350);
    stu.show();
    Student* pstu1 = new Student("林文浩", 21, 270);
    pstu1->show();
}