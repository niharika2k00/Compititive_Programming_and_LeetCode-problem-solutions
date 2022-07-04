/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 */

// @lc code=start
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size(), i, res = 0, one = 0, right = 0, start = 0, prevZeroIndex = -1;

        if (one == n)
            return n - 1;

        while (right < n)
        {
            if (nums[right] == 0)
            {
                if (prevZeroIndex != -1) //  zero encounter NOT 1st time(Window Shrink)
                    start = prevZeroIndex + 1;

                prevZeroIndex = right;
            }

            res = max(res, right - start + 1);
            right++;
        }

        return res - 1;
    }
};
// @lc code=end
