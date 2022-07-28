/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int len = numbers.size(), i = 0;
        int j = len - 1;

        // ------------------------------
        //  Two Pointers   TC : O(n)
        // ------------------------------
        while (i < j)
        {
            int sum = numbers[i] + numbers[j];
            if (sum == target)
                return {i + 1, j + 1};

            else if (sum > target)
                j--;

            else
                i++;
        }

        return {i + 1, j + 1};

        // ------------------------------
        //  Binary Search   TC : O(nlogn)
        // ------------------------------
        int low = 0, high = len - 1, find = 0;

        for (i = 0; i < len - 1; i++)
        {
            find = target - numbers[i];
            low = i + 1;
            high = len - 1;

            while (low <= high)
            {
                int mid = low + (high - low) / 2;

                if (numbers[mid] == find)
                    return {i + 1, mid + 1}; //  return index

                else if (numbers[mid] > find)
                    high = mid - 1;

                else
                    low = mid + 1;
            }
        }

        return {};
    }
};
// @lc code=end
