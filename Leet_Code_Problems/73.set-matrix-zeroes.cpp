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

        //  Now revert all the 1e9 to 0
        for (int row = 0; row < ROW; row++)
        {
            for (int col = 0; col < COL; col++)
            {
                if (matrix[row][col] == maxi)
                    matrix[row][col] = 0;
            }
        }
    }

    // --------------------------------------
    //           Better Solution     TC :  O(N*M + N*M)  ,  SC : O(N)
    // --------------------------------------
    /* void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> dummy1(rows, -1), dummy2(cols, -1); //  1D matrix

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    dummy1[i] = 1;
                    dummy2[j] = 1;
                }
            }
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                if (dummy1[i] == 1 || dummy2[j] == 1)
                    matrix[i][j] = 0;
        }
    } */

    // --------------------------------------
    //           Best Solution     TC :   O(2*(N*M))  ,  SC : O(1)
    // --------------------------------------
    void setZeroes(vector<vector<int>> &matrix)
    {
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

        for (int i = 0; i < rows; i++)
        {
            // checking if 0 is present in the 0th column or not
            if (matrix[i][0] == 0)
                col0 = 0;
            for (int j = 1; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // traversing in the reverse direction and
        // checking if the row or col has 0 or not
        // and setting values of matrix accordingly.
        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j > 0; j--)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }

            if (col0 == 0)
                matrix[i][0] = 0;
        }
    }
};

// @lc code=end