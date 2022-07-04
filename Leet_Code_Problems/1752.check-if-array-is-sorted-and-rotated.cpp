/*
 * @lc app=leetcode id=1752 lang=cpp
 *
 * [1752] Check if Array Is Sorted and Rotated
 */

// @lc code=start
class Solution
{
public:
    bool check(vector<int> &nums)
    {

        int i, count = 0, size = nums.size();
        for (i = 0; i < size; i++)
        {
            if (nums[i] > nums[(i + 1) % size])
                count++;
        }

        return (count <= 1);
    }
};
// @lc code=end
