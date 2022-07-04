/*
 * @lc app=leetcode id=1624 lang=cpp
 *
 * [1624] Largest Substring Between Two Equal Characters
 */

// @lc code=start
class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {

        unordered_map<char, int> map; // key: character, value: least index of character in s
        int len = -1, compare;
        for (int i = 0; i < s.length(); i++)
        {
            if (map.count(s[i])) // whether this ele is present or not
            {
                compare = i - map[s[i]] - 1;
                len = max(len, compare);
            }
            else
                map[s[i]] = i;
        }
        return len;
    }
};
// @lc code=end
