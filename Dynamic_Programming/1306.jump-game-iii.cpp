/*
 * @lc app=leetcode id=1306 lang=cpp
 *
 * [1306] Jump Game III
 */

// DYNAMIC PROGRAMMING  -----  RECURSIVE METHOD
// @lc code=start
class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        int result = 0, rightside = 0, leftside = 0, len = arr.size();

        if (start < 0 || start >= len || arr[start] == -1) //  Boundary Condition  +  Visited  Check
            return false;

        if (arr[start] == 0)
            return true;

        // Leftside and Rightside Jumps
        leftside = start - arr[start];
        rightside = start + arr[start];

        arr[start] = -1;

        result = canReach(arr, leftside) || canReach(arr, rightside);

        return result;
    }
};
// @lc code=end
