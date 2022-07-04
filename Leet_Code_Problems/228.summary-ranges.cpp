/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * https://leetcode.com/problems/summary-ranges/
 *
 * [228] Summary Ranges
 */

// @lc code=start
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        int len = nums.size(), start = 0, i = 0;
        vector<string> ranges;

        if (len == 0)
            return ranges;

        while (i < len)
        {
            if (i == len - 1 || nums[i] + 1 != nums[i + 1]) // when NEXT ele === prev + 1   (Skip)
            {
                if (start == i)
                    ranges.push_back(to_string(nums[start]));
                else
                    ranges.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));

                start = i + 1;
            }

            i++;
        }

        return ranges;
    }
};
// @lc code=end
