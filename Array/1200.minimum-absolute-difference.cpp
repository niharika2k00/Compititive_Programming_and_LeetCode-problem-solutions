/*
 * @lc app=leetcode id=1200 lang=cpp
 *
 * [1200] Minimum Absolute Difference
 *
 * https://leetcode.com/problems/minimum-absolute-difference/
 *
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        vector<vector<int>> result;
        int minDifference = INT_MAX, i = 0, len = arr.size();
        sort(arr.begin(), arr.end());

        for (i = 1; i < len; i++)
            if (minDifference > (arr[i] - arr[i - 1]))
                minDifference = arr[i] - arr[i - 1];
        // minDifference = min(minDifference, (arr[i] - arr[i - 1]));

        for (i = 1; i < len; i++)
            if (arr[i] - arr[i - 1] == minDifference)
                result.push_back({arr[i - 1], arr[i]});

        return result;
    }
};
// @lc code=end
