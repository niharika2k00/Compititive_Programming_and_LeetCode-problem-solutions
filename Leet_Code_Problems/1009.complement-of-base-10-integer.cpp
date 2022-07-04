/*
 * @lc app=leetcode id=1009 lang=cpp
 *
 * [1009] Complement of Base 10 Integer
 */
// https://leetcode.com/problems/complement-of-base-10-integer/
// @lc code=start
class Solution
{
public:
    int bitwiseComplement(int n)
    {
        int ans = 0, mask = 0, num = n;

        // Base Case
        if (n == 0)
            return 1;

        while (num != 0)
        {
            num = num >> 1;
            mask = (mask << 1) | 1; //  Left shift +  Bitwise OR
        }

        ans = (~n) & mask;
        return ans;
    }
};
// @lc code=end
