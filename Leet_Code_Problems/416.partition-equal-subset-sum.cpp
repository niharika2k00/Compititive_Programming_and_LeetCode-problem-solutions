/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution
{
public:
    bool hasEqualPartition(vector<int> &arr, int len, int target, vector<vector<int>> &Dp)
    {
        if (target == 0)
            return true;

        if (len == 0 && target != 0)
            return false;

        if (Dp[len][target] != -1)
            return Dp[len][target];

        if (arr[len] > target) // exclude
            return Dp[len][target] = hasEqualPartition(arr, len - 1, target, Dp);

        bool consider = hasEqualPartition(arr, len - 1, target - arr[len], Dp);
        bool notConsider = hasEqualPartition(arr, len - 1, target, Dp);

        return Dp[len][target] = consider || notConsider;
    }

    bool canPartition(vector<int> &nums)
    {
        int len = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 == 1) // Odd
            return false;

        sum = sum / 2; // Divide by 2 and search in the whole arr for the partition.

        vector<vector<int>> Dp(len + 1, vector<int>(sum + 1, -1));
        bool res = hasEqualPartition(nums, len - 1, sum, Dp);

        return res;
    }
};

// @lc code=end
