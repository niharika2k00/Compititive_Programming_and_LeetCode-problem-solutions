/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/
 *
 */

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // Time Complexity : O(m * n)
        //  Space Complexity : O(1)
        int i = 0;
        for (i = 0; i < n; i++)
        {
            nums1[m] = nums2[i];
            m++;
        }

        sort(nums1.begin(), nums1.end());

        //  We can also use MAX - HEAP
    }
};
// @lc code=end
