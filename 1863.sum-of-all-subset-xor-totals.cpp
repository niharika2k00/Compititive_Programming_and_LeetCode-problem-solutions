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
        int xor_sum = 0, i;
        int limit = (2 * nums.size()) - 1;

               for (i = 0; i <= limit; i++)
        {
            xor_sum = xor_sum + i;
        }

        return xor_sum;
    }
};
// @lc code=end
