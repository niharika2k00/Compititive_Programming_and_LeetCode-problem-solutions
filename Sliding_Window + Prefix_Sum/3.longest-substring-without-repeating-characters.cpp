/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
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
