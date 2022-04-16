/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * https://leetcode.com/problems/set-matrix-zeroes/
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int maxi = 1e9;
        int ROW = matrix.size(), COL = matrix[0].size();

        for (int row = 0; row < ROW; row++)
        {
            for (int col = 0; col < COL; col++)
            {
                if (matrix[row][col] == 0)
                    matrix[row][col] = maxi;
            }
        }

        for (int row = 0; row < ROW; row++)
        {
            for (int col = 0; col < COL; col++)
            {
                if (matrix[row][col] == maxi)
                {
                    //  all elements of the ROW = 0 (Horizontally)
                    for (int i = 0; i < COL; i++)
                        if (matrix[row][i] != maxi)
                            matrix[row][i] = 0;

                    //  all elements of the COL = 0 (Vertical)
                    for (int j = 0; j < ROW; j++)
                        if (matrix[j][col] != maxi)
                            matrix[j][col] = 0;
                }
            }
        }

        for (int row = 0; row < ROW; row++)
        {
            for (int col = 0; col < COL; col++)
            {
                if (matrix[row][col] == maxi)
                    matrix[row][col] = 0;
            }
        }
    }
};

// @lc code=end
