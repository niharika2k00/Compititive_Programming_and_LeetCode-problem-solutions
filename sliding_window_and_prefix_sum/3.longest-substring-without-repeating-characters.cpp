/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i, start = 0, end = 0, maxLength = 0, temp = 0, windowSize;

        if (s.size() == 0)
            return 0;

        unordered_map<char, int> map;

        for (end = 0; end < s.size(); end++)
        {
            map[s[end]]++;
            // cout << "Size of map = " << map.size() << endl;
            windowSize = end - start + 1;

            if (map.size() == windowSize)
                maxLength = max(maxLength, windowSize);

            else if (map.size() < windowSize)
            {
                while (map.size() < windowSize)
                {
                    map[s[start]]--;

                    if (map[s[start]] == 0)
                        map.erase(s[start]);

                    start++;
                    windowSize = end - start + 1;
                }
            }
        }

        return maxLength;
    }
};
// @lc code=end

// --------------------------------
//          Method 2
// --------------------------------
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> hashMap;
        int len = s.size(), r = 0, l = 0, res = 0;

        for (r = 0; r < len; r++)
        {
            hashMap[s[r]]++;

            while (hashMap[s[r]] > 1)
            {
                hashMap[s[l]]--; // remove elements from the beginning
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};
