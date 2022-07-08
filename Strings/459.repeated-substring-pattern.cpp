/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 *
 * https://leetcode.com/problems/repeated-substring-pattern/description/
 *
 */

// @lc code=start
class Solution
{
public:
    //  Remove first char to avoid to match with input string which is from 0 to s.length()
    //  Remove last char - appended after s.length()
    //  Search for the input string is repeated

    bool repeatedSubstringPattern(string s)
    {
        string tmp = s + s;

        tmp = tmp.substr(1);
        tmp = tmp.substr(0, tmp.length() - 1);
        return tmp.find(s) != string::npos ? true : false;
    }
};
// @lc code=end
