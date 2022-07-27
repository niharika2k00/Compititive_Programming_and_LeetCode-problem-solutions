/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 *
 * https://leetcode.com/problems/next-greater-element-ii/
 *
 *  CIRCULARLY FINDING NEXT GREATER ELEMENT
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int len = arr.size();

        stack<int> s;
        vector<int> result(len, -1);

        for (int i = 2 * len - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top() <= arr[i % len])
                s.pop();

            if (i < len && !s.empty())
            {
                int nge = s.top();
                // result.push_back(nge ?  nge :  -1);
                result[i] = nge;
            }

            s.push(arr[i % len]);
        }

        return result;
    }
};
// @lc code=end
