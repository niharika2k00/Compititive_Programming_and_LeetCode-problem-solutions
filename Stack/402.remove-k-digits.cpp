/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

// @lc code=start
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int len = num.length();
        stack<char> Stack;

        //  If the coming ele is LESS than the prev ele then POP prev ele, as due to that PEAK encountered
        for (auto ele : num)
        {
            while (!Stack.empty() && k > 0 && ele < Stack.top())
            {
                k--;
                Stack.pop();
            }

            if (!Stack.empty() || ele != '0')
                Stack.push(ele);
        }

        //  CASE : when the values are in INCEREASING order(Ex - 1 4 9 14), then none of the ele has been POPED OUT
        while (!Stack.empty() && k > 0)
        {
            Stack.pop();
            k--;
        }

        if (Stack.empty())
            return "0";

        // Now prepare the OUTPUT String  ==>  Result.
        while (!Stack.empty())
        {
            num[len - 1] = Stack.top();
            Stack.pop(), len--;
        }

        return num.substr(len);
    }
};
// @lc code=end
