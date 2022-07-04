/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int lenPattern = p.length(), lenStr = s.length(), i;
        int windowLen = lenPattern;
        vector<int> result;
        unordered_map<char, int> stringMap, patternMap; // Two HashMap for storing the count

        if (lenPattern > lenStr)
            return result;

        //  Window SIZE of both the strings initialises into the HashMap
        for (i = 0; i < lenPattern; i++)
        {
            stringMap[s[i]]++;
            patternMap[p[i]]++;
        }

        if (stringMap == patternMap)
            result.push_back(0);

        for (i = lenPattern; i < lenStr; i++)
        {
            //  ADD next char  &&  REMOVE previous char
            stringMap[s[i]]++;
            stringMap[s[i - windowLen]]--;

            if (stringMap[s[i - windowLen]] == 0)
                stringMap.erase(s[i - windowLen]);

            if (stringMap == patternMap)
                result.push_back(i - windowLen + 1);
        }

        return result;
    }
};
// @lc code=end
