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
    static bool compare(vector<int> a, vector<int> b)
    {
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        //   METHOD  - I   ||    Using MultiMap
        //  Time Complexity :  O(n)
        //  Space Complexity :  O(n)
        int len = boxTypes.size(), res = 0;
        multimap<int, int, greater<int>> multiMap; //  sort desc units

        for (int i = 0; i < len; i++)
            multiMap.insert({boxTypes[i][1], boxTypes[i][0]}); // store  {boxUnit , numOfBox}     insert(pair<int, int>(3, 60));

        for (auto it : multiMap)
        {
            if (truckSize >= it.second) //  means need 10 box but present 3, so obviously will take all of them
            {
                res = res + (it.first * it.second);
                truckSize = truckSize - it.second;
            }
            else
            {
                res = res + (truckSize * it.first);
                return res;
            }
        }
        return res;

        //      METHOD  - II   ||    Using Normal Sort
        //  Time Complexity :  O(nlogn)
        //  Space Complexity :  O(1)
        sort(boxTypes.begin(), boxTypes.end(), compare); //  Sort by Box Units

        for (int i = 0; i < len; i++)
        {
            if (truckSize >= boxTypes[i][0])
            {
                res = res + (boxTypes[i][0] * boxTypes[i][1]);
                truckSize = truckSize - boxTypes[i][0];
            }
            else
            {
                res = res + (truckSize * boxTypes[i][1]);
                return res;
            }
        }
        return res;
    }
};
// @lc code=end
