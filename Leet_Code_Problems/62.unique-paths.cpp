/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

/*
https://leetcode.com/problems/unique-paths/

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
 */
// @lc code=start
class Solution
{
public:
    // Time Complexity : O(mn)
    // Space Complexity : O(mn)

    // ---------------------------
    // MEMOIZATION OR TOP-DOWN APPROACH
    // ---------------------------
    int path(int m, int n, vector<vector<int>> &dp)
    {
        if (m == 0 || n == 0 || dp.size() == 0)
            return 1;

        if (dp[m][n] != -1) //  Not -1
            return dp[m][n];

        dp[m][n] = path(m - 1, n, dp) + path(m, n - 1, dp);
        return dp[m][n];
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1)); // 2D vector initialised -1
        return path(m - 1, n - 1, dp);
    }
};

// @lc code=end

/*
---------------------------
// BOTTOM UP METHOD
---------------------------

   int a[m][n];
        for(int i=0;i<m;i++)
            a[i][0]=1;
        for(int i=0;i<n;i++)
            a[0][i]=1;
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
              a[i][j]=a[i-1][j]+a[i][j-1];
        return a[m-1][n-1];

 */