/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution
{
public:
    //  Using Sort Functionality
    //  Time Complexity :  O(nlogn)
    //  Space Complexity : O(1)
    int longestConsecutive(vector<int> &nums)
    {
        int len = nums.size(), i, maxLen = 1, store = 0;

        if (len == 0)
            return 0;

        if (len == 1)
            return 1;

        sort(nums.begin(), nums.end());

        for (i = 1; i < len; i++)
        {
            if (nums[i - 1] != nums[i]) // for testcase like [1,2,0,1]  =>  [0,1,1,2]
            {
                if (nums[i - 1] + 1 == nums[i])
                    maxLen++;
                else
                {
                    store = max(store, maxLen);
                    maxLen = 1;
                }
            }
        }

        store = max(store, maxLen);
        return store;

        //  Using Hash Map
        //  Time Complexity :  O(n)
        //  Space Complexity :  O(n)

        unordered_map<int, int> hashMap;

        for (int i = 0; i < len; i++)
            hashMap[arr[i]]++;

        for (int i = 0; i < len; i++)
        {
            if (hashMap.find(arr[i] - 1) != hashMap.end()) //  prev term if found
                continue;
            else
            {
                currNum = arr[i];
                currStreak = 1;

                while (hashMap.find(currNum + 1) != hashMap.end())
                {
                    currNum += 1;
                    currStreak += 1;
                }
            }
            res = max(res, currStreak);
        }

        return res;
    }
};
// @lc code=end

/*                       Intuition
                   ----------------------

    #  Search for the previous term in the hashMap  ==> if found CONTINUE
    #  ELSE search for the next term.
    #  Track the longest streak
 */