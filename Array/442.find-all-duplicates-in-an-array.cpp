/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> vec;

        //  METHOD - I
        //  Time Complexity :  O(N)
        //   Space Complexity :  O(N)
        unordered_map<int, int> map;

        for (int i = 0; i < len; i++)
        {
            if (map[nums[i]] == 0)
                map[nums[i]]++;

            else
                vec.push_back(nums[i]);
        }

        //  METHOD - II
        //  Time Complexity :  O(N)
        //   Space Complexity :  O(1)
        for (int i = 0; i < len; i++)
        {
            int n = abs(nums[i]); // 4

            if (nums[n - 1] < 0)
                vec.push_back(abs(nums[i])); //  i is the index of the repeated num

            else
                nums[n - 1] *= (-1);
        }

        return vec;
    }
};
// @lc code=end
