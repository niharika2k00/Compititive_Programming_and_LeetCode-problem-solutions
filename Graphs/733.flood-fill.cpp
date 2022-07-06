/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */
// https://leetcode.com/problems/flood-fill/

// @lc code=start
class Solution
{
public:
    void DFS(vector<vector<int>> &image, int rows, int cols, int newColor, int sr, int sc, int start)
    {
        if (sr >= rows || sc >= cols || sr < 0 || sc < 0 || image[sr][sc] != start)
            return;

        image[sr][sc] = newColor;

        DFS(image, rows, cols, newColor, sr + 1, sc, start);
        DFS(image, rows, cols, newColor, sr - 1, sc, start);
        DFS(image, rows, cols, newColor, sr, sc + 1, start);
        DFS(image, rows, cols, newColor, sr, sc - 1, start);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if (newColor == image[sr][sc]) // If same no need to alter
            return image;

        int start = image[sr][sc], rows = image.size(), cols = image[0].size();

        DFS(image, rows, cols, newColor, sr, sc, start);
        return image;
    }
};
// @lc code=end

/* 
                            ------------------
                                APPROACH 
                            ------------------

     1) 4-diagonally means in all the 4 direction traverse using DFS.
     2) Starting Coordinate (sr, sc)  then convert the image number to newColor.



 */