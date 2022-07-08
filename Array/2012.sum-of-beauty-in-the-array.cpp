/*
 * @lc app=leetcode id=2012 lang=cpp
 *
 * [2012] Sum of Beauty in the Array
 *
 * https://leetcode.com/problems/sum-of-beauty-in-the-array/
 *
 */

// @lc code=start
class Solution
{
public:
    int sumOfBeauties(vector<int> &arr)
    {
        int len = arr.size(), sum = 0, val = INT_MIN;
        vector<int> prefix(len), suffix(len);

        //   Prefix Max array
        for (int i = 0; i < len; i++)
        {
            val = max(val, arr[i]);
            prefix[i] = val;
        }

        val = INT_MAX;

        //    Suffix Max array
        for (int i = len - 1; i >= 0; i--)
        {
            val = min(val, arr[i]);
            suffix[i] = val;
        }

        for (int i = 1; i < len - 1; i++)
        {
            if (prefix[i - 1] < arr[i] && arr[i] < suffix[i + 1])
                sum += 2;

            else if (arr[i - 1] < arr[i] && arr[i] < arr[i + 1])
                sum += 1;

            // else add 0.
        }

        return sum;
    }
};
// @lc code=end
