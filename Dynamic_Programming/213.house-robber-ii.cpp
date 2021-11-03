/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int i, len = nums.size();
        if (len == 0)
            return 0;
        if (len == 1)
            return nums[0];

        vector<int> dp(len, 0);

        // When Rob takes place within 2nd house  and Last house
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (i = 2; i < len; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        int notLast = dp[len - 2];

        // When Rob takes place within Last house(exlusive)
        dp[0] = 0;
        dp[1] = nums[1];

        for (i = 2; i < len; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        int last = dp[len - 1];

        return max(notLast, last);
    }
};
// @lc code=end
