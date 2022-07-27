/*
 * @lc app=leetcode id=1365 lang=cpp
 *
 * [1365] How Many Numbers Are Smaller Than the Current Number
 *
 * https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        int len = arr.size(), i;
        unordered_map<int, int> hashMap;
        vector<int> temp = arr; //  stores the original array

        //    O(nlogn)
        sort(temp.begin(), temp.end()); //   1 2 2 3 8

        hashMap.insert({temp[0], 0});

        for (i = 1; i < len; i++)
        {
            if (temp[i - 1] != temp[i]) // check whether prev term is same or not
                hashMap.insert({temp[i], i});
        }

        for (int i = 0; i < len; i++)
            temp[i] = hashMap[arr[i]];

        return temp;
    }
};
// @lc code=end
