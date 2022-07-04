/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * https://leetcode.com/problems/search-a-2d-matrix/
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        //   Sorted Matrix so Binary Search can be applied
        int col = matrix[0].size(), row = matrix.size(), low, high, mid = 0;
        // cout << row << " " << col << endl;
        low = 0, high = (row * col) - 1;

        if (!row)
            return false;

        while (low <= high)
        {
            mid = (low + high) / 2;

            if (matrix[mid / col][mid % col] == target)
                return true;

            else if (matrix[mid / col][mid % col] > target)
                high = mid - 1;

            else
                low = mid + 1;
        }

        return false;
    }
};
// @lc code=end
