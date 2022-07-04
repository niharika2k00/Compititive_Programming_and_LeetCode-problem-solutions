/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/
 *
//  Sort an array consisting of 0s, 1s and 2s WITHOUT USING inbuild func. The functions should put all 0s first, then all 1s and all 2s in last.
//   Time Complexity :  O(n)
//   Space Complexity :  O(1)
//   Counting Sort || Dutch National FLag Algorithm
 */

// @lc code=start

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {

        int len = nums.size();
        int start = 0, end = len - 1, mid = 0;

        while (mid <= end)
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid], nums[start]);
                start++;
                mid++;
            }

            else if (nums[mid] == 2)
            {
                swap(nums[mid], nums[end]);
                end--;
            }

            else if (nums[mid] == 1)
                mid = mid + 1;
        }
    }
};

// @lc code=end
