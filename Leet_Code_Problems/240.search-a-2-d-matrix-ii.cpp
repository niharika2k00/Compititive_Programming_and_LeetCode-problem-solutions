/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/
 *
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size(), col = matrix[0].size();
        int r = 0, c = col - 1; // initially we are starting from Row 1 , Col last

        while (r >= 0 && r < row && c >= 0 && c < col)
        {
            if (target == matrix[r][c])
                return true;

            else if (target > matrix[r][c])
                r++; // means prev row strike off

            else
                c--;
        }

        return false;
    }
};
// @lc code=end
