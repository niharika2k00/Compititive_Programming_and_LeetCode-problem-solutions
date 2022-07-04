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

    // -----------------------------------
    // MEMOIZATION OR TOP-DOWN APPROACH
    // -----------------------------------
    int path(int row, int col, int i, int j, vector<vector<int>> &dp)
    {
        if (i == row - 1 && j == col - 1)
            return 1;

        //  Out of Bounds.
        if (i >= row || j >= col)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        dp[i][j] = path(row, col, i, j + 1, dp) + path(row, col, i + 1, j, dp); //  right + bottom
        return dp[i][j];
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1)); // 2D vector initialised -1

        return path(m, n, 0, 0, dp);
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