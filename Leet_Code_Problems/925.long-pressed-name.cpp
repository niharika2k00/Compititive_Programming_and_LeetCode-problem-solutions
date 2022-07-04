/*
 * @lc app=leetcode id=925 lang=cpp
 *
 * [925] Long Pressed Name
 */

// @lc code=start
class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        int n = name.size(), m = typed.size(), j = 0, i = 0;

        while (j < m)
        {
            if (name[i] == typed[j])
            {
                i++;
                j++;
            }
            else if (j != 0 && typed[j] == typed[j - 1])
                j++;

            else
                return false;
        }

        return i == n;
    }
};
// @lc code=end
