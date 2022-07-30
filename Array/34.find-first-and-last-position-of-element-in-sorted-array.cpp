/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &arr, int target)
    {
        int len = arr.size(), flag = 1, start = -1, end = -1;

        for (int i = 0; i < len; i++)
        {
            if (arr[i] == target && flag)
            {
                start = i;
                end = i; // this step is bcz if there is only 1 element and start end both will be same.
                flag = 0;
                continue;
            }

            else if (arr[i] == target)
                end = i;
        }

        if (start != -1 && end != -1)
            return {start, end};

        return {-1, -1};
    }
};
// @lc code=end
