/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution
{
public:
    // KADANES ALGORITMS  --->   largest contiguous subarray
    int maxSubArray(vector<int> &nums)
    {
        int i, len = nums.size(), maxSum = 0, currentSum = 0, count = 0;

        // All Negetive elements present in the array  [-1]  OR  [-2,-1]
        for (i = 0; i < len; i++)
            if (nums[i] < 0)
                count++;

        if (count == len)
            return *max_element(nums.begin(), nums.end());

        // General Kadanes algorithm
        for (i = 0; i < len; i++)
        {
            currentSum += nums[i];
            maxSum = max(maxSum, currentSum);

            if (currentSum < 0) // negative sum
                currentSum = 0;
        }
        return maxSum;
    }
};
// @lc code=end

/*
 int currentSum =nums[0], totalSum = nums[0];
          for(int i=1; i<nums.size(); i++) {

            currentSum = max(nums[i], currentSum+nums[i]);
            totalSum = max(totalSum, currentSum);
    }
        return totalSum;
 */