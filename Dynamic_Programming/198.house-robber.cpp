/*
 * @lc app=leetcode id=198 lang=cpp
 *  https://leetcode.com/problems/house-robber/
 * [198] House Robber
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &A, vector<int> &dp, int i)
    {
        if (i >= size(A))
            return 0;
        if (dp[i] != -1)
            return dp[i];
        return dp[i] = max(rob(A, dp, i + 1), A[i] + rob(A, dp, i + 2));
    }

    int rob(vector<int> &nums)
    {
        int len = nums.size(), prev2 = 0, prev = 0, cur = 0;

        // METHOD - 1
        vector<int> dp(len, -1);
        return rob(nums, dp, 0);

        // METHOD - 2
        for (auto i : nums)
        {
            cur = max(prev, i + prev2);
            prev2 = prev; //  as alternate
            prev = cur;
        }
        return cur;
    }
};
// @lc code=end
