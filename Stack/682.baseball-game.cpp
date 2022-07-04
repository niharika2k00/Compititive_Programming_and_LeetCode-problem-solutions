/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 */

// @lc code=start
class Solution
{
public:
    bool isNumber(string str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (isdigit(str[i]) == false)
                return false;
        }

        return true;
    }

    int calPoints(vector<string> &ops)
    {
        int len = ops.size(), sum = 0;
        stack<int> stack; //  we can also perform using Vector

        for (int i = 0; i < len; i++)
        {
            if (ops[i] == "+")
            {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.push(a);
                stack.push(a + b);
            }

            else if (ops[i] == "D")
            {
                int prev = stack.top();
                stack.push(prev * 2);
            }

            else if (ops[i] == "C")
                stack.pop();

            else
            {
                stack.push(stoi(ops[i]));
                // if (isNumber(ops[i]))
                // stack.push(i);
            }
        }

        while (!stack.empty())
        {
            sum = sum + stack.top();
            stack.pop();
        }

        return sum;
    }
};
// @lc code=end
