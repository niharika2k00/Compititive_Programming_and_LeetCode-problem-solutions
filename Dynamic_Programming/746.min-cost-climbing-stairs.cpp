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
        int i, len = cost.size(); //  zero indexing
        int dp[len];

        dp[0] = cost[0];
        dp[1] = cost[1];

        if (len == 0)
            return 0;

        for (i = 2; i < len; i++)
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);

        return min(dp[len - 2], dp[len - 1]);

        // --------------------------------------------------------------------
        vector<int> dp(len + 1, 0);

        for (int i = 2; i <= len; i++)
        {
            int jumpOneStep = dp[i - 1] + cost[i - 1];
            int jumpTwoStep = dp[i - 2] + cost[i - 2];

            dp[i] = min(jumpOneStep, jumpTwoStep);
        }

        return dp[len];
    }
};
// @lc code=end

/* This is a classic Dynamic Programming problem.
      # Let dp[i] is the minimum cost to reach to i_th floor.
      # To reach to i_th floor, we have 2 ways:
      # Jump 1 step from (i-1)th floor, dp[i] = dp[i-1] + cost[i-1]
      # Jump 2 steps from (i-2)th floor, dp[i] = dp[i-2] + cost[i-2]
      # dp[i] = minimum cost between 2 above ways.
      # Finally, dp[n] is minimum cost to reach to the top of the floor.


# Example
Input: cost = [10, 15, 20]

                                   ___________
                         ________ | Top floor
            ___________ |   20
__________ | 15 (start)
10 (start)



Hence , DONE.
 */