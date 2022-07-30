/*
 * @lc app=leetcode id=1402 lang=cpp
 *
 * [1402] Reducing Dishes
 *
 * https://leetcode.com/problems/reducing-dishes/
 *
 */

// @lc code=start
class Solution
{
public:
    int knapsackPatternRecursion(vector<int> &arr, int len, int i, int time)
    {
        //  Base Case or outOfBound
        if (len == i)
            return 0;

        int include = (arr[i] * time) + knapsackPattern(arr, len, i + 1, time + 1); // already picked so go for the next one
        int exclude = knapsackPattern(arr, len, i + 1, time);

        int res = max(include, exclude);
        return res;
    }

    int knapsackPatternMemoized(vector<int> &arr, int len, int i, int time, vector<vector<int>> &dp)
    {
        //  Base Case or outOfBound
        if (len == i)
            return 0;

        if (dp[i][time] != -1)
            return dp[i][time];

        int include = (arr[i] * time) + knapsackPattern(arr, len, i + 1, time + 1, dp); // already picked so go for the next one
        int exclude = knapsackPattern(arr, len, i + 1, time, dp);

        int res = max(include, exclude);
        return dp[i][time] = res;
    }

    //  Main Function
    int maxSatisfaction(vector<int> &satisfaction)
    {
        int len = satisfaction.size(), sum = 0, count = 0, res = 0;
        sort(satisfaction.begin(), satisfaction.end());

        // ----------------------------------
        //      METHOD - I
        // Sorting Algorithm
        // ----------------------------------
        for (int i = len - 1; i >= 0; i--)
        {
            sum += satisfaction[i];

            if (sum < 0)
                break;

            count++;
        }

        count = len - count; // 5 - 3
        int time = 1;        //  as 1 unit of time req

        for (int i = count; i < len; i++)
        {
            res += satisfaction[i] * time;
            time++;
        }

        return res;

        // ----------------------------------
        //      METHOD - II
        // Dynamic Programming Approach
        // ----------------------------------
        vector<vector<int>> dp(len + 1, vector<int>(len + 1, -1));
        return knapsackPatternMemoized(satisfaction, len, 0, 1, dp);
    }
};
// @lc code=end
