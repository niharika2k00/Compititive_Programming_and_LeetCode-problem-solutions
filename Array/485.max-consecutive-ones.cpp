/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 *
 * https://leetcode.com/problems/max-consecutive-ones/
 *
 */

// @lc code=start
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &arr)
    {
        int len = arr.size(), res = 0, count = 0;

        if (arr[0] == 1 && len == 1)
            return 1;

        for (int i = 0; i < len; i++)
        {
            if (arr[i] == 1)
            {
                count++;
                res = max(res, count);
            }
            else
                count = 0;
        }

        return res;
    }
};
// @lc code=end
