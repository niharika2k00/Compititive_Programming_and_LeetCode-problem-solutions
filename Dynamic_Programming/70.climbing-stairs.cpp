/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */
// https://leetcode.com/problems/climbing-stairs/
// @lc code=start
class Solution
{
public:
    int helper(int n, vector<int> &dp)
    {
        if (n <= 2)
            return n;

        if (dp[n] != -1)
            return dp[n];

        dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
        return dp[n];
    }

    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }
};
