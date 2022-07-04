/*
 * @lc app=leetcode id=1465 lang=cpp
 *
 * [1465] Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
 *
 * https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
 *
 */

// @lc code=start
class Solution
{
public:
    int maxDistance(vector<int> arr, int len)
    {
        int maxDiff = arr[0];

        for (int i = 1; i < arr.size(); i++)
            maxDiff = max(maxDiff, arr[i] - arr[i - 1]);

        // consider the last cut
        maxDiff = max(maxDiff, len - arr.back()); // (vertical - 1) = 4 - 1 = 3 max

        return maxDiff;
    }

    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        long long int maxArea = 0, maxHt = 0, maxWidth = 0;

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        maxHt = maxDistance(horizontalCuts, h);
        maxWidth = maxDistance(verticalCuts, w);

        maxArea = (maxHt * maxWidth) % 1000000007;

        return maxArea;
    }
};
// @lc code=end
