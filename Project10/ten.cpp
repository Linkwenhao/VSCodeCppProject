#include <iostream>
using namespace std;

//基类
class People
{
public:
    void setName(string name);
    void setAge(int age);
    void setNickname(string nickname);
    string getName();
    int getAge();
    string getNick();

private:
    string m_name;
    int m_age;
    string m_nickname;
};

void People::setName(string name)
{
    m_name = name;
}

void People::setAge(int age)
{
    m_age = age;
}

void People::setNickname(string nickname)
{
    m_nickname = nickname;
}

string People::getName()
{
    return m_name;
}

int People::getAge()
{
    return m_age;
}

string People::getNick()
{
    return m_nickname;
}

//派生类
class Student : public People
{
public:
    void setscore(float score);
    float getscore();

private:
    float m_score;
};

void Student::setscore(float score)
{
    m_score = score;
}
float Student::getscore()
{
    return m_score;
}

int main()
{
    Student stu;
    stu.setName("韦旭贤");
    stu.setAge(18);
    stu.setNickname("wxx");
    stu.setscore(99999);
    cout << stu.getName() << stu.getAge() << stu.getNick() << stu.getscore() << endl;
}