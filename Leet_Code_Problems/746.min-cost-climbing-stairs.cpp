/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {

        int i, len = cost.size();  //  zero indexing 
        int dp[len];

        dp[0] = cost[0];
        dp[1] = cost[1];

        if (len == 0)
            return 0;

        for (i = 2; i < len; i++)
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);

        return min(dp[len - 2], dp[len - 1]);
    }
};
// @lc code=end
