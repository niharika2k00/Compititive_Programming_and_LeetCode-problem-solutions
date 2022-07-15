/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &arr)
    {
        //  Brute Force Approach  TC : n2   SC : 1
        //  / Divide Operator use in place TC : O(n)
        //  Using Prefix && Suffix Product   TC : O(n)    SC : O(n)

        int len = arr.size();
        vector<int> preProd(len), suffProd(len), res(len);

        preProd[0] = 1;
        for (int i = 1; i < len; i++)
            preProd[i] = arr[i - 1] * preProd[i - 1];

        suffProd[len - 1] = 1;
        for (int i = len - 2; i >= 0; i--)
            suffProd[i] = arr[i + 1] * suffProd[i + 1];

        for (int i = 0; i < len; i++)
            res[i] = preProd[i] * suffProd[i];

        return res;
    }
};
// @lc code=end
