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
    int climbStairs(int n)
    {
        int Z;
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;
        if (n < 0)
            return 0;

        Z = climbStairs(n - 1) + climbStairs(n - 2);
        return Z;
    }
};
// @lc code=end

// WRONG -----> DO USING DP
