
// https://leetcode.com/problems/maximum-subarray/
class Solution
{
public:
    // Kaldane's Algotithm
    int helper1(vector<int> &vec, int len)
    {
        int currSum = 0, maxSum = 0, count = 0;
        // All Negetive elements present in the array  [-1]  OR  [-2,-1]
        for (int i = 0; i < len; i++)
            if (vec[i] < 0)
                count++;

        if (count == len)
            return *max_element(vec.begin(), vec.end());

        for (int i = 0; i < len; i++)
        {
            currSum = currSum + vec[i];

            if (currSum < 0)
                currSum = 0;

            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }

    // Using 1D DP
    int helper2(vector<int> &vec, int len)
    {
        int currSum = vec[0], maxSum = vec[0];

        for (int i = 1; i < len; i++)
        {
            currSum = max(currSum + vec[i], vec[i]);
            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }

    int maxSubArray(vector<int> &nums)
    {
        int len = nums.size();

        // return helper1(nums, len);
        return helper2(nums, len);
    }
};