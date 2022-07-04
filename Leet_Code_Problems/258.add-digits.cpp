/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
class Solution
{
public:
    int addDigits(int num)
    {
        if (num < 10)
            return num;

        int k, sum = 0;

        while (num >= 10)
        {
            sum = 0;
            while (num)
            {
                k = num % 10;
                sum = sum + k;
                num = num / 10;
            }

            num = sum;
        }

        return num;
    }
};
// @lc code=end
