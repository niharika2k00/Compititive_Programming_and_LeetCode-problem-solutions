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
        // int Z;
        // if (n == 0 || n < 1)
        //     return 1;
        // if (n < 0)
        //     return 0;

        // Z = climbStairs(n - 1) + climbStairs(n - 2);
        // return Z;

        int step[45], i;
        step[0] = 1;
        step[1] = 2;
        for (i = 2; i < n; i++)
            step[i] = step[i - 1] + step[i - 2];

        return step[n - 1];
    }
};
// @lc code=end

// WRONG -----> DO USING DP
