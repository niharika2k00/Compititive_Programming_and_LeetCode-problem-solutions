/*
 * @lc app=leetcode id=1647 lang=cpp
 *
 * [1647] Minimum Deletions to Make Character Frequencies Unique
 *
 * https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
 *
 */

// @lc code=start
class Solution
{
public:
    int minDeletions(string s)
    {
        int len = s.size(), res = 0;
        unordered_map<char, int> hashMap;
        unordered_map<int, int> freqMap;

        for (int i = 0; i < len; i++)
            hashMap[s[i]]++;

        for (auto it : hashMap)
        {
            int freq = it.second; // freq of a char

            if (freqMap.find(freq) != freqMap.end()) // If found
            {
                while (freq > 0 && freqMap.find(freq) != freqMap.end())
                {
                    freq--;
                    res++;
                }
            }

            if (freq > 0)
                freqMap[freq]++;
        }

        return res;
    }
};
// @lc code=end
