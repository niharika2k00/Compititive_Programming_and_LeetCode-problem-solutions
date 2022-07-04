/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution
{
public:
    //  TC :  O(N^2)   SC : O(1)
    void rotate(vector<vector<int>> &matrix)
    {
        int len = matrix.size(), i, j;

        //  Transpose of the Matrix   arr[i][j] convert to arr[j][i]
        for (i = 0; i < len; i++)
            for (j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);

        //  Reverse the ROWS
        for (i = 0; i < len; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};

// @lc code=end
