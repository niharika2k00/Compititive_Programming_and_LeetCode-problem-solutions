/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int len = nums.size(), i, reachable = 0, jumps = 0, maxReachable = 0;

        if (nums[0] == 0 && len == 1) // [0]
            return 0;

        if (nums[0] == 0 || len == 1) // Start 0
            return 0;

        // Peak Valley Approach  <------  GREEDY APPROACH
        for (i = 0; i < len - 1; i++)
        {
            if (reachable < i)
                return 0;

            reachable = max(reachable, i + nums[i]);
            if (maxReachable == i)
            {
                jumps++;
                maxReachable = reachable;
            }
        }

        return jumps;
    }
};
// @lc code=end
