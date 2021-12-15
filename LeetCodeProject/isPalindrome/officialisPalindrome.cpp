#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        // 特殊情况：
        // 如上所述，当 x < 0 时，x 不是回文数。
        // 同样地，如果数字的最后一位是 0，为了使该数字为回文，
        // 则其第一位数字也应该是 0
        // 只有 0 满足这一属性
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }

        //翻转一半数字 `1221`后一半`21`翻转后`12`与前一半相等即为回文
        //当翻转后的数字大于或等于原数字即可停止，即翻转后数字小于原数字为while循环条件
        int revertedNumber = 0;
        while (x > revertedNumber)
        {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
        // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
        // 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
        return x == revertedNumber || x == revertedNumber / 10; // 12 == 123%10 --> 12 == 12
    }
};

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