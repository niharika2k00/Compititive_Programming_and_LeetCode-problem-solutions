/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        // PRINT THE ELEMENT THAT OCCURS ONLY ONCE
        int i, len = nums.size(), num = 0;
        unordered_set<int> Set;

        for (i = 0; i < len; i++)
        {
            if (Set.find(nums[i]) == Set.end()) //  if nums[i]  not present in the SET
                Set.insert(nums[i]);
            else
                Set.erase(nums[i]);
        }

        auto it = Set.begin();
        return *it;
    }
};
// @lc code=end

/*
             Here we can also do this using BITWISE OPERATOR
             as 2 XOR 2 = 0

             So, all values will be 0 except one

             for(int i = 0; i < len ; i++)
                ans = ans + ans ^ nums[i];

 */

/*
             AN ALTERNATIVE OF THIS

               if (Set.find(nums[i]) == Set.end())
                             IS

                   if ( Set.count(nums[i]) )
 */