/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int len = nums.size(), i, reachable = 0, count = 0;

        if (nums[0] == 0 && len == 1) // [0]
            return true;

        if (nums[0] == 0)
            return false;

        // Peak Valley Approach  <------  GREEDY APPROACH
        for (i = 0; i < len; i++)
        {
            if (i > reachable) // could not react Index
                return false;

            reachable = max(reachable, i + nums[i]); //  Index Trace

            if (reachable >= len)
                return true;
        }

        return true;
    }
};
// @lc code=end
