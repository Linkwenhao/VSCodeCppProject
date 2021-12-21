#include <iostream>
using namespace std;

class Stu
{
public:
    Stu(string name);
    string getName() const;
    void show();

private:
    const string m_name;
};

Stu::Stu(string name) : m_name(name)
{
}
string Stu::getName() const
{
    return m_name;
}
void Stu::show()
{
    cout << " " << m_name << endl;
}

int main()
{
    Stu *p = new Stu("微博");
    p->show();
    string name = p->getName();
    cout << "name:" << name << endl;

    const Stu stu("李育琪");
    // stu.show();    error
    cout << "const name: " << stu.getName() << endl;

    const Stu *cp = new Stu("李育琪");
    // cp->show();    error
    cout << "const name: " << cp->getName() << endl;
}