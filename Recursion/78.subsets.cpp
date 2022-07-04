/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * https://leetcode.com/problems/subsets/
 *
 * [78] Subsets
 */

// @lc code=start
class Solution
{
public:
    //  Backtracking Problem ,   draw the RECURSION TREE
    vector<vector<int>> result;

    void helper(int i, vector<int> &nums, vector<int> temp)
    {
        if (i == nums.size())
        {
            result.push_back(temp);
            return;
        }

        helper(i + 1, nums, temp); //  exclude the current element
        temp.push_back(nums[i]);
        helper(i + 1, nums, temp); // include element part
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> temp;
        int i, len = nums.size();

        helper(0, nums, temp);
        return result;
    }
};
// @lc code=end
