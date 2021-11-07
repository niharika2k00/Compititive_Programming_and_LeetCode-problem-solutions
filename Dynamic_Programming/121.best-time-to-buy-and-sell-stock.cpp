/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // BRUTE FORCE APPROACH
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

        int ret = 0, maxProfit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            ret += prices[i] - prices[i - 1];
            if (ret < 0)
                ret = 0;
            maxProfit = max(maxProfit, ret);
        }
        return maxProfit;
    }
};
// @lc code=end
