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
        int i, j;
        for (i = 0; i < grid.size(); ++i)
        {
            for (j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j]) //  Land = 1
                    return dfs(i, j, grid);
            }
        }

        return 0;
    }

    int dfs(int i, int j, vector<vector<int>> &grid)
    {

        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == 0)
            return 1;

        if (grid[i][j] == -1) //  already visited
            return 0;

        grid[i][j] = -1; //    Marked Current Box VISITED

        return dfs(i + 1, j, grid) + dfs(i - 1, j, grid) + dfs(i, j + 1, grid) + dfs(i, j - 1, grid);
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

     Complexity : O(mn) time and O(1) Space
     
 */
