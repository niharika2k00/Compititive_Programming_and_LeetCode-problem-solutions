/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 *
 * https://leetcode.com/problems/find-the-town-judge/
 *
 */

// @lc code=start
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        int i, prev = 0, flag = 0;
        if (n == 2)
            return trust[0][1];

        prev = trust[0][1];

        for (i = 1; i < n; i++)
        {
            if (prev == trust[i][1])
                prev = trust[i][1];
            else
                flag = 1;
        }

        if (flag == 1)
            return -1;

        return prev;
    }
};
// @lc code=end
