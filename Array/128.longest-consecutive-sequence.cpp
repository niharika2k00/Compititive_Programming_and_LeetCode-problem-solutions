/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution
{
public:
    //  Time Complexity :  O(nlogn)
    //  Space Complexity : O(1)
    int longestConsecutive(vector<int> &nums)
    {
        int len = nums.size(), i, maxLen = 1, store = 0;

        if (len == 0)
            return 0;

        if (len == 1)
            return 1;

        sort(nums.begin(), nums.end());

        for (i = 1; i < len; i++)
        {
            if (nums[i - 1] != nums[i]) // for testcase like [1,2,0,1]  =>  [0,1,1,2]
            {
                if (nums[i - 1] + 1 == nums[i])
                    maxLen++;
                else
                {
                    store = max(store, maxLen);
                    maxLen = 1;
                }
            }
        }

        store = max(store, maxLen);

        return store;
    }
};
// @lc code=end
