/*
 * @lc app=leetcode id=1578 lang=cpp
 *
 * https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
 *
 * [1578] Minimum Time to Make Rope Colorful
 */

// @lc code=start
class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime) // colors = [a,a,b,b]
    {
        int ans = 0, i, len = colors.size(), prevMaxTime = neededTime[0];
        char prevColor = colors[0];

        if (len == 0)
            return 0;

        for (i = 1; i < len; i++)
        {
            if (colors[i] == prevColor)
            {
                ans = ans + min(prevMaxTime, neededTime[i]);
                prevMaxTime = max(prevMaxTime, neededTime[i]);
            }

            else
            {
                prevColor = colors[i];
                prevMaxTime = neededTime[i];
            }
        }

        return ans;
    }
};

// @lc code=end
