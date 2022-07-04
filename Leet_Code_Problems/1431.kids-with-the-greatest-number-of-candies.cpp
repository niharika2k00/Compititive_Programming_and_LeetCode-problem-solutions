/*
 * @lc app=leetcode id=1431 lang=cpp
 *
 * [1431] Kids With the Greatest Number of Candies
 */

// @lc code=start
class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        vector<bool> out;
        int max = *max_element(candies.begin(), candies.end());

        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i] + extraCandies >= max)
                out.push_back(true);
            else
                out.push_back(false);
        }

        return out;
    }
};
// @lc code=end
