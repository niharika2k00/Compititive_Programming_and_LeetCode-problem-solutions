/*
 * @lc app=leetcode id=820 lang=cpp
 *
 * https://leetcode.com/problems/short-encoding-of-words/
 *
 * [820] Short Encoding of Words
 */

// @lc code=start
bool compare(string &a, string &b)
{
    return a.length() > b.length();
}

class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {
        int len = words.size(), i;

        // sort(words.begin() , words.end() , greater<string>());
        sort(words.begin(), words.end(), compare); // reverse sort by length

        string res = "";
        res = res + words[0] + "#";

        for (i = 1; i < len; i++)
        {

            //  If found  returns the index of the first occurrence of sub-string
            int isFind = res.find(words[i] + "#");
            if (isFind >= 0)
                continue;
            else
                res = res + words[i] + "#";
        }

        cout << res << endl;
        return res.size();
    }
};
// @lc code=end

/*
Sort Reverse using Length so that put the large string at the beginning.

["time","me","bell"]         ==>      time#bell#

["time","atime","btime"]       ==>    atime#btime#

 */