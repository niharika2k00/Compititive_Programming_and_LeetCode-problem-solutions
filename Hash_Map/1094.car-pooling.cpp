/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
class Solution
{
public:
    /*
          0  ->  Passenger
          1  ->  Start
          2  ->  End
     */
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        // Ordered Map as we have to sort
        map<int, int> hashMap;
        int currPassenger = 0;

        for (auto arr : trips)
        {
            hashMap[arr[1]] += arr[0]; //  add passsenger start time
            hashMap[arr[2]] -= arr[0]; //  delete at end / drop when they reach
        }

        for (auto it : hashMap)
        {
            currPassenger = currPassenger + it.second;
            if (currPassenger > capacity)
                return false;
        }

        return true;
    }
};
// @lc code=end
