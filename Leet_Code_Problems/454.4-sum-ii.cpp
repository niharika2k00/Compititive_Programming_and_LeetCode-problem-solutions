/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        int count = 0;
        unordered_map<int, int> mp;

        //   Store the addition of 2 num from both the array in HASHMAP and find whether (-1) of that num is present in the Map or Not.
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                int sum = nums1[i] + nums2[j];
                mp[sum]++;
            }
        }

        for (int i = 0; i < nums3.size(); i++)
        {
            for (int j = 0; j < nums4.size(); j++)
            {
                int sum = -1 * (nums3[i] + nums4[j]);
                if (mp[sum])
                    count += mp[sum];
            }
        }

        return count;
    }
};
// @lc code=end
