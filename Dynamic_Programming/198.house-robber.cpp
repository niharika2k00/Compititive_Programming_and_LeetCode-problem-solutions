/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        // USING IF - ELSE
        // int i, len = nums.size(), sum1 = 0, sum2 = 0;

        // for (i = 0; i < len; i++)
        // {
        //     if (i % 2 == 0) // even
        //     {
        //         sum1 = sum1 + nums[i];
        //         sum1 = max(sum1, sum2);
        //     }
        //     else
        //     {
        //         sum2 = sum2 + nums[i];
        //         sum2 = max(sum2, sum1);
        //     }
        // }

        // return max(sum1, sum2);

        // USING LOOP
        int len = nums.size(), i;
        vector<int> dp(len, 0);

        if (nums.empty() || len == 0)
            return 0;
        if (len == 1)
            return nums[0];

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (i = 2; i < len; ++i)
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        return dp[len - 1]; // dp[3] for len = 4(zero indexing) , 0 1 2 3
    }
};
// @lc code=end
