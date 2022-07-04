/*
 * @lc app=leetcode id=198 lang=cpp
 *  https://leetcode.com/problems/house-robber/
 * [198] House Robber
 */

// @lc code=start
class Solution
{
public:
    int HelperFunction(vector<int> &A, vector<int> &dp, int i)
    {
        if (i >= size(A))
            return 0;
        if (dp[i] != -1)
            return dp[i];
        return dp[i] = max(HelperFunction(A, dp, i + 1), A[i] + HelperFunction(A, dp, i + 2));
    }

    int rob(vector<int> &nums)
    {
        int len = nums.size(), i, prev2 = 0, prev = 0, cur = 0;

        //   METHOD - 1  - Recursion Approach -->  Top Down Approach
        vector<int> dp(len, -1);
        // return HelperFunction(nums, dp, 0);

        //   METHOD - 2  - Buttom - Up Approach
        vector<int> arr(len, 0);
        if (len == 0)
            return 0;
        if (len >= 1)
            arr[0] = nums[0];
        if (len >= 2)
            arr[1] = max(nums[0], nums[1]);

        for (i = 2; i < len; i++)
            arr[i] = max(arr[i - 1], nums[i] + arr[i - 2]);

        return arr[len - 1];
    }
};
// @lc code=end
