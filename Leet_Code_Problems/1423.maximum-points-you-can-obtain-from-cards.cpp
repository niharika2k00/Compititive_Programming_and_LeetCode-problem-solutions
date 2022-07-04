/*
 * @lc app=leetcode id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
 *
 * https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
 *
 */

// @lc code=start
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int len = cardPoints.size(), right = 0, left = len - 1, maxSum = 0, currWindowSum = 0;

        int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        // cout << totalSum ;

        // Maximize subarray sum of size k
        right = len - k;

        if (k == len)
            return totalSum;

        for (int i = 0; i < right; i++)
            currWindowSum += cardPoints[i];

        maxSum = totalSum - currWindowSum;

        //  sliding window
        for (int i = right; i < len; i++)
        {
            currWindowSum = currWindowSum + cardPoints[i] - cardPoints[i - right]; //  current window sum, but we want sum of [Total - Window].
            maxSum = max(totalSum - currWindowSum, maxSum);
        }

        return maxSum;
    }
};
// @lc code=end
