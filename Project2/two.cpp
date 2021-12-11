#include <iostream>
using namespace std;

class Stu
{
public:
    Stu(string name, int age, float score);
    void show();

public:
    static int getTotal();  //获取静态变量
    static int getPoints(); //

private:
    static int m_total;  //总人数
    static int m_points; //总分

private:
    string m_name;
    int m_age;
    float m_score;
};

int Stu::m_total = 0;
int Stu::m_points = 0;

Stu::Stu(string name, int age, float score) : m_name(name), m_age(age), m_score(score)
{
    m_total++;
    m_points += score;
}

void Stu::show()
{
    cout << " " << m_name << " " << m_age << " " << m_score << endl;
    cout << "total  " << m_total << "  points  " << m_points << endl;
}

int Stu::getTotal(){
    return m_total;
}

int Stu::getPoints(){
    return m_total;
}

int main(){
    (new Stu("lwh",20,270))->show();
    (new Stu("lyq",21,350))->show();
    int t=Stu::getTotal();
    int p=Stu::getPoints();
}