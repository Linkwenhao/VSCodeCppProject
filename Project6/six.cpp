#include <iostream>
#include <string>
using namespace std;

class A
{
public:
    A(string str);
    void indexshow() const;        //下标遍历
    void alter(char c, int index); //根据下标修改

private:
    string m_str;
};

A::A(string str) : m_str(str)
{
}
void A::indexshow() const
{
    for (int i = 0; i < m_str.length(); i++)
    {
        cout << "`" << m_str[i] << "`" << ends;
    }
    cout << endl;
}

void A::alter(char c, int index)
{
    m_str[index] = c;
}

int main()
{
    const char *s1 = "cpp";
    char s3[] = "cpp";
    string s2 = "c plus plus";
    string s4 = s2;
    string s5 = s2 + "  " + s1; // 拼接 必须要有一个string
    cout << "s5 = " << s5 << endl;
    cout << "s4.length() = " << s4.length() << endl;
    cout << "s4 = " << s4 << endl;
    const char *p = s4.c_str();
    cout << "const char * p = " << p << endl;
    cout << " *p = " << *p << endl;
    cout << "const char * s4.c_str() = " << s4.c_str() << endl;

    A arr("abcdefg");
    arr.indexshow();
    arr.alter('c', 0);
    arr.indexshow();
    return 0;
}

// 输出结果
// s5 = c plus plus  cpp
// s4.length() = 11
// s4 = c plus plus
// const char * p = c plus plus
//  *p = c
// const char * s4.c_str() = c plus plus
// `a``b``c``d``e``f``g`
// `c``b``c``d``e``f``g`