/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// https://leetcode.com/problems/longest-palindromic-substring/
// @lc code=start
class Solution
{
public:
    int expandAroundCenter(string str, int left, int right)
    {
        while (left >= 0 && right < str.length() && str[left] == str[right])
        {
            left--;
            right++;
        }

        return (right - left - 1);
    }

    string longestPalindrome(string s)
    {
        int n = s.length();
        if (n < 2)
            return s;

        int start = 0, end = 0;

        for (int i = 0; i < n; i++)
        {
            //  for ODD length string
            int len1 = expandAroundCenter(s, i, i);

            // for EVEN length string
            int len2 = expandAroundCenter(s, i, i + 1);

            int len = max(len1, len2);

            if (len > (end - start))
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }

        //        JAVA :  Str.substring(beginIndex , endIndex)        (start , end + 1)
        //         C++ : string.substr(position , len)
        return s.substr(start, end - start + 1);
    }
};
// @lc code=end
