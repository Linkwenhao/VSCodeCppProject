#include <iostream>
using namespace std;

class Solution
{
public:
    string toLowerCase(string s);
};

string Solution::toLowerCase(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 65  && s[i] <= 90)
        {
            s[i] |= 32;
        }
    }
    return s;
}

int main()
{
    Solution sol;
    string name = "Hello GxuCtf";
    cout << sol.toLowerCase(name) << endl;
}