/*
 * @lc app=leetcode id=1863 lang=cpp
 *
 * [1863] Sum of All Subset XOR Totals
 */

// @lc code=start
class Solution
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        // Obsesrve that after performing the sum we are actually performing the addition upto 2^n - 1.
        int xor_sum = 0, i, or_total = 0, length = nums.size();
        int limit = pow(2, length - 1);

        for (i = 0; i < length; ++i)
        {
            or_total = or_total | nums[i];
        }

        xor_sum = limit * or_total;
        return xor_sum;
    }
};
// @lc code=end
