/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/
 *
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        int len = s.size();

        if (len == 1)
            return false;

        stack<char> stk;

        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                stk.push(s[i]);

            else if (stk.empty())
                return false;

            else
            {
                char ele = stk.top();
                stk.pop();

                if ((s[i] == ')' && ele == '(') || (s[i] == '}' && ele == '{') || (s[i] == ']' && ele == '['))
                    continue;

                else
                    return false;
            }
        }

        if (stk.empty())
            return true;

        return false;
    }
};
// @lc code=end
