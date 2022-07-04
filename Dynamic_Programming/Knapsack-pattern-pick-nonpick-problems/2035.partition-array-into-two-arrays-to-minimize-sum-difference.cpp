/*
 * @lc app=leetcode id=2035 lang=cpp
 *
 * [2035] Partition Array Into Two Arrays to Minimize Sum Difference
 */

// @lc code=start
class Solution
{
public:
    /*

     */
    int MinimizeDiff(vector<int> &nums, int len, int totalSum, int currSum, vector<vector<int>> &dp)
    {
        // Base Case            when iterator reaches the first Index  +   LEN  =  0 arr has nly 1 element
        if (len == 0)
            return abs(totalSum - 2 * currSum);
        //         return abs((totalSum - currSum) - currSum );

        if (dp[len][currSum] != -1)
            return dp[len][currSum];

        int consider = MinimizeDiff(nums, len - 1, totalSum, currSum + nums[len], dp);
        int notConsider = MinimizeDiff(nums, len - 1, totalSum, currSum, dp);

        return dp[len][currSum] = min(consider, notConsider);
    }

    int minimumDifference(vector<int> &nums)
    {
        int totalSum = 0, n = nums.size();
        for (int i = 0; i < n; i++)
            totalSum = totalSum + nums[i];

        vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));
        int res = MinimizeDiff(nums, n - 1, totalSum, 0, dp);

        return res;
    }
};

// @lc code=end
