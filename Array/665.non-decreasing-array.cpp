/*
 * @lc app=leetcode id=665 lang=cpp
 *
 * [665] Non-decreasing Array
 *
 * https://leetcode.com/problems/non-decreasing-array/
 *
 */

// @lc code=start
class Solution
{
public:
    //  VIDEO  :   https://www.youtube.com/watch?v=RegQckCegDk
    bool checkPossibility(vector<int> &nums)
    {
        int len = arr.size();
        bool isChange = false;

        for (int i = 0; i < len - 1; i++)
        {
            if (arr[i] <= arr[i + 1])
                continue;
            if (isChange)
                return false;

            //  Cases :  [7 8 1 8]
            if (i == 0 || arr[i + 1] >= arr[i - 1]) // if [4 2] for that edge case [i == 0] checking.
                arr[i] = arr[i + 1];
            else
                arr[i + 1] = arr[i];

            isChange = true;
        }

        return true;
    }
};
// @lc code=end
