/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 *
 * https://leetcode.com/problems/longest-palindromic-subsequence/
 *
 */

// @lc code=start
class Solution
{
public:
    int palindromicLCS(vector<vector<int>> &Dp, string &str, string &rev, int m, int n)
    {
        if (m == 0 || n == 0)
            return 0;

        if (Dp[m][n] != -1)
            return Dp[m][n];

        if (str[m - 1] == rev[n - 1])
            return Dp[m][n] = 1 + palindromicLCS(Dp, str, rev, m - 1, n - 1);

        else
            return Dp[m][n] = max(palindromicLCS(Dp, str, rev, m - 1, n), palindromicLCS(Dp, str, rev, m, n - 1));
    }

    int longestPalindromeSubseq(string s)
    {
        string rev = s;     //  "bbbab"
        int len = s.size(); // 5
        reverse(rev.begin(), rev.end());

        vector<vector<int>> Dp(len + 1, vector<int>(len + 1, -1));

        return palindromicLCS(Dp, s, rev, len, len);
    }
};
// @lc code=end
