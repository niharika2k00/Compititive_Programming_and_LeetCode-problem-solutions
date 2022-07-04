/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * https://leetcode.com/problems/majority-element/
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution
{
public:
    //  Time Complexity :  O(n)       ------   Using HashMap
    //  Space Complexity :  O(n)
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> hashMap;
        int len = nums.size(), i, maxEle = len / 2, ans = 0;

        for (i = 0; i < len; i++)
            hashMap[nums[i]]++;

        for (auto it : hashMap)
        {
            if (it.second > maxEle)
                ans = it.first;
        }

        return ans;
    }

    //  Time Complexity :  O(n)       ------   Using Moore's Majority Algorithm
    //  Space Complexity :  O(1)
    int majorityElement(vector<int> &nums)
    {
    }
};

// @lc code=end
