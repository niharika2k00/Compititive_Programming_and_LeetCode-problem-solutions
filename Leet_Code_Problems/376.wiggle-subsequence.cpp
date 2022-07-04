/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 *
 * https://leetcode.com/problems/wiggle-subsequence/
 *
 */

// @lc code=start
class Solution
{
public:
    int wiggleMaxLength(vector<int> &arr)
    {
        int len = arr.size(), count = 0, prev, currDiff;

        if (len == 0 || len == 1)
            return len;

        prev = arr[1] - arr[0];
        count = (prev != 0) ? 2 : 1;

        for (int i = 2; i < len; i++)
        {
            currDiff = arr[i] - arr[i - 1];
            if ((currDiff > 0 && prev <= 0) || (currDiff < 0 && prev >= 0))
            {
                count++;
                prev = currDiff;
            }
        }

        return count;
    }
};
// @lc code=end
