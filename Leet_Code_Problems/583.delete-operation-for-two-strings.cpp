/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 *
 * https://leetcode.com/problems/delete-operation-for-two-strings/
 *
 */

// @lc code=start
class Solution
{
public:
    int LCS(string a, string b, int m, int n, vector<vector<int>> &memo)
    {
        if (m == 0 || n == 0)
            return 0;

        if (memo[m][n] != -1)
            return memo[m][n];

        if (a[m - 1] == b[n - 1])
            memo[m][n] = 1 + LCS(a, b, m - 1, n - 1, memo);

        else
            memo[m][n] = max(LCS(a, b, m - 1, n, memo), LCS(a, b, m, n - 1, memo));

        return memo[m][n];
    }

    int minDistance(string word1, string word2)
    {
        int len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> memo(len1 + 1, vector<int>(len2 + 1, -1));

        int dpResult = LCS(word1, word2, len1, len2, memo);
        int res = len1 + len2 - 2 * dpResult;

        return res;
    }
};
// @lc code=end

/*
                                  VARIATION OF LCS
                         -----------------------------------

                sea | eat ==> LCS is 2, that is, "ea"
sea's length is 3 ==> thus the number of characters that are not in the LCS are 3 - 2 = 1
eat's length is 3 ==> thus the number of characters that are not in the LCS are 3 - 2 = 1
therefore, the total delete distance of the whole is 1 + 1 = 2

 */