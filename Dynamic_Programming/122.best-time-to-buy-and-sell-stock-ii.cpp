/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0, p;
        for (p = 1; p < prices.size(); ++p)
            ans += max(prices[p] - prices[p - 1], 0);
        return ans;
    }
};
// @lc code=end
