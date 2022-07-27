/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int len = numbers.size(), i = 0;
        int j = len - 1;

        while (i < j)
        {
            int sum = numbers[i] + numbers[j];
            if (sum == target)
                return {i + 1, j + 1};

            else if (sum > target)
                j--;

            else
                i++;
        }

        return {i + 1, j + 1};
    }
};
// @lc code=end
