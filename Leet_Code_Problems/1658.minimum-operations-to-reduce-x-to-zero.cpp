/*
 * @lc app=leetcode id=1658 lang=cpp
 *
 * https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/
 *
 * [1658] Minimum Operations to Reduce X to Zero
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int len = nums.size(), sum = 0, subArrSum = 0, maxLength = -1;
        int i = 0, j = 0;

        sum = accumulate(nums.begin(), nums.end(), 0);

        if (x > sum)
            return -1;
        int remain = sum - x; //  11 - 5 = 6

        // Now we have to find the Longest Subarray with  SUM  = 6
        for (i = 0; i < len; i++)
        {
            subArrSum += nums[i];

            while (subArrSum > remain)
            {
                subArrSum = subArrSum - nums[j]; // delete the first element from the window
                j++;
            }

            if (subArrSum == remain)
                maxLength = max(maxLength, i - j + 1);
        }

        return maxLength == -1 ? -1 : len - maxLength;
    }
};

// @lc code=end

/*
           INTUITION / APPROACH
         ---------------------------

    1) Find the total sum of the ARR, then subtract X from it.
    2) Means we got the remaining SUM = (total - X) . So now find the LONGEST SUBARRAY with remaining SUM
                using the sliding window method.

 */