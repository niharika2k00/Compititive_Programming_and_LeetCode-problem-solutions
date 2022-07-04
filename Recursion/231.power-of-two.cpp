/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        bool ans = false;
        if (n == 1)
            return true;

        if (n && n % 2 == 0) // if N Exsist + Even.
            ans = isPowerOfTwo(n / 2);

        return ans;
    }
};
// @lc code=end
