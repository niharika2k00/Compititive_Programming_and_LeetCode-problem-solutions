/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        // int i, ans = 0;
        // for (i = 0; i < nums.size(); i++)
        //     ans = ans ^ nums[i]; //  Xor of 2 ^ 2 = 0
        // return ans;

        unordered_map<int, int> map;
        int i, ans = 0;

        for (i = 0; i < nums.size(); i++)
            map[nums[i]]++;

        for (auto j = map.begin(); j != map.end(); j++)
        {
            if (j->second == 1)
                ans = j->first;
        }

        return ans;
    }
};
// @lc code=end
