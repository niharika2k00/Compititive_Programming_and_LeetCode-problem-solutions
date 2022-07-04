/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/
 *
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {

        int len = s.size(), i = 0, j = 0;
        string res;

        while (i < len)
        {
            // Skip the empty spaces - gaps
            while (i < len && s[i] == ' ')
                i++;

            if (i >= len)
                break; // edge case

            j = i + 1;

            //  Iterate the word free of space
            while (j < len && s[j] != ' ')
                j++;

            string word = s.substr(i, j - i); //  substr( start , len)

            if (res.size() == 0)
                res = word;
            else
                res = word + " " + res;

            i = j + 1; // set start(i) to the last of the prev word
        }

        return res;
    }
};
// @lc code=end
