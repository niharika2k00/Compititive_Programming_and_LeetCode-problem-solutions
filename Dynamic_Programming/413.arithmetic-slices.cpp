/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int i, len = nums.size(), ans = 0;
        vector<int> dp(len, 0); //  initalises with 0

        if (len < 3)
            return 0;

        for (i = 1; i < len - 1; i++)
        {
            if (nums[i] - nums[i - 1] == nums[i + 1] - nums[i])
            {
                // it will consider the whole means in [3 -1 -5 -9]   3 -1 -5   and  -1 -5 9 both will be considered when dp[i] = 2;
                dp[i] = dp[i - 1] + 1;
                ans = ans + dp[i];
            }
        }

        return ans;
    }
};
// @lc code=end
