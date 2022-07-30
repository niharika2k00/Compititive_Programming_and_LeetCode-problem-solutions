/*
 * @lc app=leetcode id=890 lang=cpp
 *
 * [890] Find and Replace Pattern
 *
 * https://leetcode.com/problems/find-and-replace-pattern/
 *
 */

// @lc code=start
class Solution
{
public:
    string getPatternCode(string pattern)
    {
        string res;
        int len = pattern.size(), num = 1;
        unordered_map<char, int> hashMap;

        for (int i = 0; i < len; i++)
        {
            if (hashMap.find(pattern[i]) == hashMap.end()) // Not Found
            {
                hashMap[pattern[i]] = num;
                num++;
            }

            res.push_back(hashMap[pattern[i]]);
        }

        return res;
    }

    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        int len = words.size();
        vector<int> result;
        string wordCode;
        string patCode = getPatternCode(pattern);

        for (int i = 0; i < len; i++)
        {
            wordCode = getPatternCode(words[i]);

            if (wordCode == patCode)
                result.push_back(words[i]);
        }

        return result;
    }
};
// @lc code=end

/*
        We are just assigning the word with unique numbers.

["abc ","  deq "," mee "," aqq "," dkd "," ccc"]
  123     123      122     122      121     111

PATTERN
   "abb"
    122

 */