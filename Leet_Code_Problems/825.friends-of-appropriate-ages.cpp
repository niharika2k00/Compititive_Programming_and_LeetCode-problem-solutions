/*
 * @lc app=leetcode id=825 lang=cpp
 *
 * https://leetcode.com/problems/friends-of-appropriate-ages/
 *
 * [825] Friends Of Appropriate Ages
 */

// @lc code=start
class Solution
{
public:
    int numFriendRequests(vector<int> &ages)
    {
        int len = ages.size(), i = 0, friendRequest = 0;
        unordered_map<int, int> hashMap; // store the frequency of all ages

        for (i = 0; i < len; i++)
            hashMap[ages[i]]++;

        for (auto &a : hashMap) //  age of Person 1
        {
            for (auto &b : hashMap) // age of Person 2
            {
                if (b.first <= 0.5 * (double)a.first + 7 || b.first > a.first || (b.first > 100 && a.first < 100))
                    continue;

                if (a.first == b.first)
                    friendRequest = friendRequest + (a.second * (a.second - 1)); // [16 , 16]   =>  2 * 1 (except herself)

                else
                    friendRequest = friendRequest + (a.second * b.second);
            }
        }

        return friendRequest;
    }
};
// @lc code=end
