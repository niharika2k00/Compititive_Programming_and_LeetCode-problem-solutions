/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 * https://leetcode.com/problems/house-robber-ii/
 */

// @lc code=start
class Solution
{
public:
    int Solve(vector<int> money)
    {
        int i, len = money.size();
        vector<int> arr(len, 0);
        if (len == 0)
            return 0;
        if (len >= 1)
            arr[0] = money[0];
        if (len >= 2)
            arr[1] = max(money[0], money[1]);

        for (i = 2; i < len; i++)
            arr[i] = max(arr[i - 1], money[i] + arr[i - 2]);

        return arr[len - 1];
    }

    int rob(vector<int> &nums)
    {
        int i, len = nums.size();
        if (len == 0)
            return 0;
        if (len == 1)
            return nums[0];

        // return ( max ( 1st house consider ,  1st house NOT consider ))  --- as Circular
        int firstInclusive = Solve(vector<int>(nums.begin(), nums.end() - 1));
        int firstExclusive = Solve(vector<int>(nums.begin() + 1, nums.end()));
        return max(firstInclusive, firstExclusive);
    }
};
// @lc code=end
