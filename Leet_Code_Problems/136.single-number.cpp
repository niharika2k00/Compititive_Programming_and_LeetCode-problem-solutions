/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int i, len = nums.size(), num = 0;
        unordered_set<int> Set;

        for (i = 0; i < len; i++)
        {
            if (Set.find(nums[i]) == Set.end()) //  if nums[i]  not present in the SET
                Set.insert(nums[i]);
            else
                Set.erase(nums[i]);
        }

        auto it = Set.begin();
        return *it;
    }
};
// @lc code=end
