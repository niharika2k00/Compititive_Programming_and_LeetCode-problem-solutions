/*
 * @lc app=leetcode id=1710 lang=cpp
 *
 * [1710] Maximum Units on a Truck
 *
 * https://leetcode.com/problems/maximum-units-on-a-truck/
 *
 */

// @lc code=start
class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        //  Using MultiMap
        //  Time Complexity :  O(n)
        //  Space Complexity :  O(n)
        int len = boxTypes.size(), res = 0;
        multimap<int, int, greater<int>> multiMap; //  sort desc units

        for (int i = 0; i < len; i++)
            multiMap.insert({boxTypes[i][1], boxTypes[i][0]}); // store  {boxUnit , numOfBox}     insert(pair<int, int>(3, 60));

        for (auto it : multiMap)
        {
            if (truckSize >= it.second) // more than box number
            {
                res = res + (it.first * it.second);
                truckSize = truckSize - it.second;
            }
            else
            {
                res = res + (truckSize * it.first);
                truckSize = 0;
            }

            if (truckSize == 0) // 0
                break;
        }
        return res;

        //  Using MultiMap
        //  Time Complexity :  O(n)
        //  Space Complexity :  O(n)
    }
};
// @lc code=end
