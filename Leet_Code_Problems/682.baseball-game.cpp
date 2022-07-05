/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 *
 * https://leetcode.com/problems/baseball-game/
 *
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
                int prev1 = stack.top();
                stack.pop();
                int prev2 = stack.top();
                stack.push(prev1);
                stack.push(prev1 + prev2);
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
            sum += stack.top();
            stack.pop();
        }

        return sum;
    }
};
// @lc code=end
