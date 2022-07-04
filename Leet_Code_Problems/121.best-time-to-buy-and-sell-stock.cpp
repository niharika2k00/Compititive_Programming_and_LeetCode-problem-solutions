/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // BRUTE FORCE APPROACH      O(n ^ 2)
        // Tle

        /*
        int maxProfit = 0, i, j, len = prices.size(), flag = 0;

        for (i = 0; i < len - 1; i++)
            for (j = i + 1; j < len; j++)
            {
                if (prices[j] > prices[i])
                    maxProfit = max(maxProfit, prices[j] - prices[i]);
            }

        return maxProfit;
         */

        int minPrice = INT_MAX, maxProfit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            //  difference between the MAX and MIN Price
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};
// @lc code=end
