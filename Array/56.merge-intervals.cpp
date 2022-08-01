/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * https://leetcode.com/problems/merge-intervals/
 *
 *  Similar Problem :  https://leetcode.com/problems/summary-ranges/
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution
{
public:
    //    O(NlogN) + O(N). O(NlogN) for sorting and O(N) for traversing through the array.
    //    Space Complexity : O(n)
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int i = 0, len = intervals.size();
        vector<vector<int>> mergedResult;

        if (len == 1)
            return intervals;

        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0], end = intervals[0][1];

        for (i = 1; i < len; i++)
        {
            if (intervals[i][0] <= end) //  IF 1st ele of arr[i + 1] <= end ele of arr[i]   ===>  then Update END (means override).
                end = max(intervals[i][1], end);
            else
            {
                mergedResult.push_back({start, end}); // push the previous Pair
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        mergedResult.push_back({start, end}); //  add the last pair

        return mergedResult;
    }
};

// @lc code=end
