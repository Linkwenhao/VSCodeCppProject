#include <iostream>
using namespace std;

//基类People
class People
{
public:
    void setname(string name);
    void setage(int age);
    void sethobby(string hobby);
    string gethobby();

protected:
    string m_name;
    int m_age;

private:
    string m_hobby;
};

void People::setname(string name)
{
    m_name = name;
}
void People::setage(int age)
{
    m_age = age;
}
void People::sethobby(string hobby)
{
    m_hobby = hobby;
}
string People::gethobby()
{
    return m_hobby;
}

//派生类Student
class Student : public People
{
public:
    void setscore(float score);

protected:
    float m_score;
};
void Student::setscore(float score)
{
    m_score = score;
}

//派生类Pupil
class Pupil : public Student
{
public:
    void setranking(int ranking);
    void display();

private:
    int m_ranking;
};
void Pupil::setranking(int ranking)
{
    m_ranking = ranking;
}
void Pupil::display()
{
    cout << m_name << "的年龄是" << m_age << "，考试成绩为" << m_score << "分，班级排名第" << m_ranking << "，TA喜欢" << gethobby() << "。" << endl;
}
int main()
{
    Pupil pup;
    pup.setname("小明");
    pup.setage(15);
    pup.setscore(92.5f);
    pup.setranking(4);
    pup.sethobby("乒乓球");
    pup.display();
    return 0;
}
