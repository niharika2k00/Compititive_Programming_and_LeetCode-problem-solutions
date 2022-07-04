/*
 * @lc app=leetcode id=62 lang=java
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {

    private int findWays(int row, int col, int[][] Dp) {
        if (row == 0 && col == 0)
            return 1;

        if (row < 0 || col < 0) // Out Of Bounds
            return 0;

        if (Dp[row][col] != -1)
            return Dp[row][col];

        int up = findWays(row - 1, col, Dp);
        int left = findWays(row, col - 1, Dp);

        return Dp[row][col] = (up + left);
    }

    public int uniquePaths(int m, int n) {

        //  Initialize 2D array to -1
        int[][] Dp = new int[m][n];
        for (int[] arr1 : Dp)
            Arrays.fill(arr1, -1);

        int result = findWays(m - 1, n - 1, Dp);
        return result;
    }
}
// @lc code=end
