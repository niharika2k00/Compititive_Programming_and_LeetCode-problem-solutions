/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int lenSubString = s.length(), lenMainString = t.length(), i = 0, j = lenSubString - 1;

        if (s == "" || t == s)
            return true;

        for (i = lenMainString; i >= 0; i--)
        {
            if (t[i] == s[j])
                j--;
            if (j < 0)
                break;
        }

        if (j < 0)
            return true;
        return false;
    }
};
// @lc code=end
