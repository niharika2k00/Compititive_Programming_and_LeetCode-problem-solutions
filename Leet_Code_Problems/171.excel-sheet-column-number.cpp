/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * https://leetcode.com/problems/excel-sheet-column-number/
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int i = 0, len = columnTitle.size(), k = 0;

        for (i = 0; i < len; i++)
            k = (k * 26) + (columnTitle[i] - 'A' + 1);

        return k;
    }
};
// @lc code=end
