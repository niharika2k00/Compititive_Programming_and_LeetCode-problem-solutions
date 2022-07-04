/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * https://leetcode.com/problems/merge-intervals/
 * Similar Problem :  https://leetcode.com/problems/summary-ranges/
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int i = 0, len = intervals.size();
        vector<vector<int>> mergedResult;

        if (len == 0)
            return mergedResult;

        if (len == 1)
            return intervals;

        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0], end = intervals[0][1];

        for (i = 1; i < len; i++)
        {
            if (end >= intervals[i][0]) //  IF 2nd ele of an arr >= 1st ele of the next arr  ===>  then Update END (means overlap).
                end = max(intervals[i][1], end);
            else
            {
                mergedResult.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        mergedResult.push_back({start, end}); //  add the last pair

        return mergedResult;
    }
};

// @lc code=end
