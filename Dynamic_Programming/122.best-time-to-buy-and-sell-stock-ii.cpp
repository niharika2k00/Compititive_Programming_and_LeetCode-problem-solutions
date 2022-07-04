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
        int maxprofit = 0, i;
        for (i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
                maxprofit += prices[i] - prices[i - 1]; //  Sum of all the drop
        }
        return maxprofit;
    }
};
// @lc code=end
