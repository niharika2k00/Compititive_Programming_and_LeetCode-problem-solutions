/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int len = nums.size(), i, sum = 0, count = 0;
        unordered_map<int, int> hashMap;

        for (i = 0; i < len; i++)
        {
            sum = sum + nums[i];
            if (hashMap.find(sum - k) != hashMap.end())
                count += hashMap[sum - k];
            if (sum == k)
                count++;
            hashMap[sum]++;
        }

        return count;
    }
};
// @lc code=end
