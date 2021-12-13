#include <iostream>
using namespace std;

class Solution
{
public:
    int reverse(int x);

private:
    int m_rev;
};

int Solution::reverse(int x)
{
    m_rev = 0;
    while (x != 0)
    {
        if (m_rev < INT_MIN / 10 || m_rev > INT_MAX / 10)
        {
            return 0;
        }
        int digit = x % 10;
        x /= 10;
        m_rev = m_rev * 10 + digit;
    }
    return m_rev;
}

int main()
{
    Solution sol;
    cout << sol.reverse(123) << endl;
}