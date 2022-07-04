/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */
//   Find MAXIMUM LENGTH of the Array with EQUAL NUMBER OF ZEROS and ONES
// @lc code=start
class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int len = nums.size(), i, maxLen = 0, sum = 0;
        unordered_map<int, int> hashMap;

        //  Array modification with 1 & -1
        for (i = 0; i < len; i++)
            nums[i] = (nums[i] == 0) ? -1 : 1;

        for (i = 0; i < len; i++)
        {
            sum = sum + nums[i];

            if (sum == 0) //  means from the beginning
                maxLen = max(maxLen, i + 1);

            // Check :  present in the Map.
            if (hashMap.find(sum) != hashMap.end()) // Present
            {
                if (i - hashMap[sum] > maxLen)
                    maxLen = i - hashMap[sum];
            }
            else
                hashMap[sum] = i;
        }

        return maxLen;
    }
};
// @lc code=end
