/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */
// https://leetcode.com/problems/island-perimeter/

// @lc code=start
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int i, j, row = grid.size(), column = grid[0].size();
        for (i = 0; i < row; ++i) //  ROW
        {
            for (j = 0; j < column; ++j) //  COLUMN
                if (grid[i][j])          //  Land = 1
                    return dfs(i, j, grid, row, column);
        }
        return 0;
    }

    int dfs(int i, int j, vector<vector<int>> &grid, int row, int column)
    {
        if (i < 0 || j < 0 || i > row - 1 || j > column - 1 || grid[i][j] == 0) //  Out of the BOUND
            return 1;

        if (grid[i][j] == -1) //  already visited
            return 0;

        grid[i][j] = -1; //    Marked Current Box VISITED

        return (dfs(i + 1, j, grid, row, column) + dfs(i - 1, j, grid, row, column) + dfs(i, j + 1, grid, row, column) + dfs(i, j - 1, grid, row, column));
    }
};

/*
                         ---------------------
                              ALGORITHM
                         ---------------------

    (1) We firstly find the beginning of island [means grid[i][j] == 1]
        Apply dfs from there
    (2) dfs function working:
        dfs(x , y grid)
        {
            if( (x,y is outside boundary of grid) OR (grid[x][y] is water cell) )
                return 1;
            if(grid[x][y] is already visited)
                return 0;

            // Reaching this line of dfs means grid[i][j] is land cell
            grid[x][y] = -1; // marking land cell as visited
            return dfs for UP + dfs for DOWN + dfs for LEFT + dfs for RIGHT;
        }

     Complexity : O(m * n) time and O(1) Space

 */