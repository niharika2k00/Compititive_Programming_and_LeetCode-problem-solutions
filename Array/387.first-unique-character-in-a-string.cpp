/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/
 *
 */

// @lc code=start
class Solution
{
public:
    int firstUniqChar(string s)
    {
        int len = s.size(), res = -1;

        unordered_map<char, int> hashMap;

        for (int i = 0; i < len; i++)
            hashMap[s[i]]++;

        for (int i = 0; i < len; i++)
        {
            if (hashMap.find(s[i]) != hashMap.end() && hashMap.at(s[i]) == 1)
                return i;
        }

        return res;
    }
};
// @lc code=end
