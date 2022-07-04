/*
 * @lc app=leetcode id=1217 lang=cpp
 *
 * [1217] Minimum Cost to Move Chips to The Same Position
 */

// @lc code=start
// GREEDY ALGORITHM

/*
      We can move all chips at EVEN positions to position 0, and chips at the ODD positions to position 1.

 */
class Solution
{
public:
    int minCostToMoveChips(vector<int> &position)
    {
        int i, len = position.size(), minPosition = 0, even = 0, odd = 0;

        //  Counting ODD and EVEN positions
        for (i = 0; i < len; i++)
        {
            if (position[i] % 2 == 0) //  EVEN position
                even++;
            else
                odd++;
        }

        minPosition = min(even, odd);
        return minPosition;
    }
};
// @lc code=end
