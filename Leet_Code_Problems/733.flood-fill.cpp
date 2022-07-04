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
    void DFS(vector<vector<int>> &image, int row, int column, int newColor, int sr, int sc, int start)
    {
        // Boundary / Base Condition
        if (sr >= row || sc >= column || sr < 0 || sc < 0 || image[sr][sc] != start)
            return;

        image[sr][sc] = newColor;

        DFS(image, row, column, newColor, sr + 1, sc, start);
        DFS(image, row, column, newColor, sr - 1, sc, start);
        DFS(image, row, column, newColor, sr, sc + 1, start);
        DFS(image, row, column, newColor, sr, sc - 1, start);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if (newColor == image[sr][sc]) // If same no need to alter
            return image;

        int start = image[sr][sc], row = image.size(), column = image[0].size();

        DFS(image, row, column, newColor, sr, sc, start);
        return image;
    }
};
// @lc code=end

/*
                            ------------------
                                APPROACH
                            ------------------

     1) Can move in all 4 direction traverse whose value EQUAL to the Source Value(1) at image[1][1].
     2) Starting Coordinate (sr, sc)  then convert the image number to newColor.
     3) Use DFS recursively.

 */