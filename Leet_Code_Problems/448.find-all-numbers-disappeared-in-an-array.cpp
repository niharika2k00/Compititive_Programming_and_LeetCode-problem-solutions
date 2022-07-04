/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int i, len = nums.size();
        vector<int> result;
        unordered_map<int, int> hashMap;

        for (i = 0; i < len; i++)
            hashMap[nums[i]]++;

        for (i = 1; i <= len; i++)
            if (hashMap.find(i) == hashMap.end()) // if NO VALUE corresponding to the index
                result.push_back(i);

        return result;
    }
};
// @lc code=end
