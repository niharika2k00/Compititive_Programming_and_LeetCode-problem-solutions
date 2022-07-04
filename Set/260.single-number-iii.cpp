/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */

// @lc code=start
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int i, num = 0;
        vector<int> ans;
        set<int> Set;

        for (i = 0; i < nums.size(); i++)
        {
            if (Set.find(nums[i]) == Set.end()) // can't find and iterator reaches the end
                Set.insert(nums[i]);
            else
                Set.erase(nums[i]);
        }

        for (auto itr = Set.begin(); itr != Set.end(); itr++)
            ans.push_back(*itr);

        return ans;
    }
};
// @lc code=end
