/*
 * @lc app=leetcode id=462 lang=cpp
 *
 * [462] Minimum Moves to Equal Array Elements II
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
 *
 */

// @lc code=start
class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        int len = arr.size(), res = 0;
        sort(arr.begin(), arr.end());

        int midIndex = len / 2;

        int midEle = arr[midIndex];

        for (int i = 0; i < len; i++)
            res += abs(nums[i] - midEle); // if abs not taken Runtime err was coming   abs(midEle - nums[i]);   &&   abs(nums[i] - midEle)

        return res;
    }
};
// @lc code=end
