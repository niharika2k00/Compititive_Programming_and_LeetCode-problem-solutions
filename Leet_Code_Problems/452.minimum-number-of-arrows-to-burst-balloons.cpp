/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start

bool comparator(vector<int> &x, vector<int> &y)
{
    return x[1] < y[1];
}

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() == 0)
            return 0;
        if (points.size() == 1)
            return 1;

        int arrow = 1, i, prevEnd;
        sort(points.begin(), points.end(), comparator);
        prevEnd = points[0][1];

        for (i = 1; i < points.size(); i++)
        {
            // If Curr Start LESS THAN prev end
            if (points[i][0] <= prevEnd) //  Overlapping
                continue;

            arrow++;
            prevEnd = points[i][1];
        }

        return arrow;
    }
};
// @lc code=end
