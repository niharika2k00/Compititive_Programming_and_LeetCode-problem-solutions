/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 */

// @lc code=start
class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {

        //   DOUBLE POINTERS  //
        int sum = 0, r = people.size() - 1, l = 0; // indexes
        sort(people.begin(), people.end());

        // for (i=0 ; l <= r ; i++)
        while (l <= r)
        {
            if (people[l] + people[r] <= limit)
                l++;
            r--;
            sum++;
        }

        return sum;
    }
};
// @lc code=end
