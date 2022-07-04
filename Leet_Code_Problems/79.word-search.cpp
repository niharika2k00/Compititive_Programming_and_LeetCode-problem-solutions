/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// https://leetcode.com/problems/word-search/
// @lc code=start
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if (DFS(0, i, j, board, word))
                    return true;
        return false;
    }

    bool DFS(int index, int x, int y, vector<vector<char>> &board, string &word)
    {
        if (index == word.size()) // word exists in matrix , if size same
            return true;

        if (x < 0 or y < 0 or x >= board.size() or y >= board[0].size() or board[x][y] == '.') // boundary check + visited check
            return false;

        if (board[x][y] != word[index])
            return false;

        char temp = board[x][y];
        board[x][y] = '.'; // marking it visited

        // Move in 4 directions[UP , DOWN , LEFT , RIGHT]
        if (DFS(index + 1, x - 1, y, board, word) or DFS(index + 1, x + 1, y, board, word) or dfs(index + 1, x, y - 1, board, word) or dfs(index + 1, x, y + 1, board, word))
            return true;

        board[x][y] = temp; // backtrack step  --> means again change as it was previous for
        return false;
    }
};
// @lc code=end
