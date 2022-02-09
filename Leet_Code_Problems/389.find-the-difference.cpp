/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * https://leetcode.com/problems/find-the-difference/
 *
 * [389] Find the Difference
 */

// @lc code=start
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        unordered_map<char, int> hashMap;
        int i, sLen = s.length(), tLen = t.length();
        char ele;

        for (i = 0; i < sLen; i++)
            hashMap[s[i]]++;

        for (i = 0; i < tLen; i++)
            hashMap[t[i]]--;

        for (auto it : hashMap)
            ele = it.first;

        return ele;
    }
};
// @lc code=end
