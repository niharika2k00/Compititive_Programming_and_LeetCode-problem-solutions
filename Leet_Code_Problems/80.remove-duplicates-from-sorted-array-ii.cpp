/*
 * @lc app=leetcode id=80 lang=cpp
 *
 *  https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i, len = nums.size(), result = len;
        map<int, int> hashMap; //  Key    Count

        for (i = 0; i < len; i++)
            hashMap[nums[i]]++;

        nums.clear();

        for (auto it = hashMap.begin(); it != hashMap.end(); it++)
        {
            if (it->second > 2)
                it->second = 2;

            for (i = 0; i < it->second; i++)
                nums.push_back(it->first);
        }

        sort(nums.begin(), nums.end());
        return nums.size(); // modified length of the vector
    }
};
// @lc code=end
