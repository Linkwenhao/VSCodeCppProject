#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x);

private:
    long m_rev;
};

bool Solution::isPalindrome(int x)
{
    {
        m_rev = 0;
        int newx = x;
        if (x == 0)
            return true;
        if (x < 0)
        {
            return false;
        }
        else
        {
            while (newx != 0)
            {
                int temp = newx % 10;
                newx /= 10;
                m_rev = m_rev * 10 + temp;
            }
            if (m_rev == x)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    Solution sol;
    if (sol.isPalindrome(1234554321))
    {
        cout << "是回文数" << endl;
    }
    else
    {
        cout << "不是回文数" << endl;
    }
}