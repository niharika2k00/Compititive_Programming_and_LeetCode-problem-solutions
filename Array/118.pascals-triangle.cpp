/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> pattern(numRows);

        for (int i = 0; i < numRows; i++)
        {
            pattern[i].resize(i + 1);
            pattern[i][0] = pattern[i][i] = 1; // Assign 1st and Last as 1

            for (int j = 1; j < i; j++)
                pattern[i][j] = pattern[i - 1][j - 1] + pattern[i - 1][j]; //  perform SUM  for the middle elements
        }

        return pattern;
    }
};

// @lc code=end

/*
  Pattern Vector will be like this :

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1

 */