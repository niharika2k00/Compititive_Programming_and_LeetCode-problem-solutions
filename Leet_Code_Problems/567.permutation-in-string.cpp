/*
 * @lc app=leetcode id=567 lang=cpp
 *
 Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

 * [567] Permutation in String
 */

// @lc code=start
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        //  Taking s1  as SMALL String
        //    SIMILAR AS ANAGRAM  STRING  CODE
        int i, lenS1 = s1.length(), lenS2 = s2.length(), windowLen;
        windowLen = lenS1;
        unordered_map<char, int> mapS1, mapS2;

        if (lenS1 > lenS2)
            return false;

        for (i = 0; i < lenS1; i++)
        {
            mapS1[s1[i]]++;
            mapS2[s2[i]]++;
        }

        if (mapS1 == mapS2)
            return true;

        //  Sliding Window Method
        for (i = lenS1; i < lenS2; i++)
        {
            //  ADD next char  &&  REMOVE previous char
            mapS2[s2[i]]++;
            mapS2[s2[i - windowLen]]--;

            if (mapS2[s2[i - windowLen]] == 0)
                mapS2.erase(s2[i - windowLen]);

            if (mapS1 == mapS2)
                return true;
        }

        return false;
    }
};
// @lc code=end
