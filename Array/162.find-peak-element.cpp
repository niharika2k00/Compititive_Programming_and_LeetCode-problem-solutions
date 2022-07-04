/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 *
 * https://leetcode.com/problems/find-peak-element/
 *
 */

// @lc code=start
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int peakElement = nums[0], i, len = nums.size();

        if (len == 0 || len == 1)
            return 0;

        if (len == 2)
            return (nums[0] > nums[1] ? 0 : 1);

        for (i = 1; i < len - 1; i++)
        {
            if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1])
                peakElement = max(peakElement, nums[i]);
        }

        auto it = find(nums.begin(), nums.end(), peakElement);
        return it - nums.begin();
    }
};
// @lc code=end
