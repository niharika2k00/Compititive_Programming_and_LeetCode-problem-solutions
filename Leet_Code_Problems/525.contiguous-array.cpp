/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */

// @lc code=start
class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int len = nums.size(), i, maxLen = 0;
        unordered_map<int, int> hashMap;

        //  Array modification with 1 & -1
        for (i = 0; i < len; i++)
            nums[i] == 0 ? -1 : 1;
    }
};
// @lc code=end
