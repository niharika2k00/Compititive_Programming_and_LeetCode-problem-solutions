/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */
//          https://leetcode.com/problems/word-break/
// @lc code=start
class Solution
{
public:
    int dp[301];

    int solve(int start, string s, set<string> &dictSet)
    {
        int len = s.length(), i;
        string temp;

        if (len == start)
            return 1;

        if (dp[start] != -1)
            return dp[start];

        for (i = start; i < len; i++)
        {
            temp = temp + s[i];
            if (dictSet.find(temp) != dictSet.end()) // search till the end
                if (solve(i + 1, s, dictSet))
                    // return 1;
                    return dp[start] = 1;
        }

        // return 0;
        return dp[start] = 0;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<string> dictSet;

        memset(dp, -1, sizeof(dp)); // initialises -1
        for (auto it : wordDict)
            dictSet.insert(it);

        return solve(0, s, dictSet);
    }
};
// @lc code=end
