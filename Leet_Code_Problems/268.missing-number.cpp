/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int len = nums.size(), i = 0, result = 0;
        //  Method - I
        sort(nums.begin(), nums.end());

        for (i = 0; i < len; i++)
        {
            if (i != nums[i])
                return i;
        }
        return i;

        //  Method - II   (Using Bits XOR)
        for (i = 0; i < len; i++)
        {
            result = result ^ i;
            result = result ^ nums[i];
        }
        return result;
    }
};
// @lc code=end
