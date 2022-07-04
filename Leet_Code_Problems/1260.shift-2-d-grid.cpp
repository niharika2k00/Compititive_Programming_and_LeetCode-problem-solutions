/*
 * @lc app=leetcode id=1260 lang=cpp
 *
 * [1260] Shift 2D Grid
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int n = grid.size();    // row
        int m = grid[0].size(); //  column
        vector<vector<int>> ans(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int newCol = (j + k) % m;           // (j + numbers of columns added)%m
                int newRow = (i + (j + k) / m) % n; // (i + numbers of rows added)%n

                ans[newRow][newCol] = grid[i][j];
            }
        }
        return ans;
    }
};
// @lc code=end
