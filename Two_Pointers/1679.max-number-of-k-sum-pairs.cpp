/*
 * @lc app=leetcode id=1679 lang=cpp
 *
 * [1679] Max Number of K-Sum Pairs
 */

// @lc code=start
class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        //  DOUBLE POINTER  //

        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1, count = 0;
        while (i < j)
        {
            if (nums[i] + nums[j] == k)
            {
                count++;
                i++;
                j--;
            }
            else if (nums[i] + nums[j] < k)
                i++;
            else
                j--;
        }

        return count;
    }
};
// @lc code=end
