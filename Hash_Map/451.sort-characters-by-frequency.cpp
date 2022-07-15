/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 *
 * https://leetcode.com/problems/sort-characters-by-frequency/
 *
 */

// @lc code=start
class Solution
{
public:
    string frequencySort(string s)
    {
        int len = s.size();
        unordered_map<char, int> hashMap; // [char , count]
        string res = "";

        for (int i = 0; i < len; i++)
            hashMap[s[i]]++;

        multimap<int, char, greater<int>> MM; // [count , char]  DESC

        for (auto &it : hashMap)
            MM.insert({it.second, it.first});
        // MM.insert({it.second , it.first});

        for (auto it : MM)
        {
            int freq = it.first;
            while (freq--)
                res += it.second;
        }

        return res;
    }
};
// @lc code=end
