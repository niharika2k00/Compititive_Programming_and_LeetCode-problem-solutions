/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * https://leetcode.com/problems/find-the-duplicate-number/
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        /*
            METHOD - I
            TIME COMPLEXITY :  O(n)
            SPACE COMPLEXITY : O(1)
         */
        int i, len = nums.size(), index = 1; // trak the last Unique Element

        if (len == 0)
            return 0;

        for (i = 0; i < len - 1; i++)
        {
            if (nums[i] != nums[i + 1])
            {
                nums[index] = nums[i + 1];
                index++;
            }
        }
        return index;
    }
};
// @lc code=end
