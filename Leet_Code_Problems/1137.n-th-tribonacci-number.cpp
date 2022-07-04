/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
class Solution
{
public:
    int tribonacci(int n)
    {
        // -------------------------
        // RECURSIVE APPROACH METHOD
        if (n == 0)
            return 0;
        else if (n == 1 || n == 2)
            return 1;
        /* else
             return (tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3)); */

        // -----------------------------------
        //  DYNAMIC PROGRAMMING APPROACH
        int dp[n + 1], i; // array to store memoization
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for (i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

        return dp[n];
    }
};
// @lc code=end
