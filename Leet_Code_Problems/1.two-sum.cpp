/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * https://leetcode.com/problems/two-sum/
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        unordered_map<int, int> hashMap;
        int i, len = nums.size(), rem = 0;

        for (i = 0; i < len; i++)
        {
            rem = target - nums[i];
            if (hashMap.find(rem) != hashMap.end()) //  found
                return {i, hashMap[rem]};

            else
                hashMap[nums[i]] = i;
        }

        return {};
    }
};
// @lc code=end
