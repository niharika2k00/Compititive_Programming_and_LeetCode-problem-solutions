/*
 * @lc app=leetcode id=1446 lang=cpp
 *
 * [1446] Consecutive Characters
 */

// @lc code=start
class Solution
{
public:
    int maxPower(string s)
    {
        int count = 1, maxCount = 0, i = 0;

        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == s[i + 1])
                count++;

            else
            {
                if (maxCount < count)
                    maxCount = count;
                count = 1;
            }
        }

        if (count > maxCount) // EDGE CASE .....
            maxCount = count;

        return maxCount;
    }
};
// @lc code=end
