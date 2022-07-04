/*
 * @lc app=leetcode id=1675 lang=cpp
 *
 * [1675] Minimize Deviation in Array
 */

// @lc code=start
class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        int i, minEle = INT_MAX, len = nums.size(), diff = INT_MAX;
        priority_queue<int> pq; //  Max Element at the TOP

        for (i = 0; i < len; i++)
        {
            if (nums[i] % 2 != 0) // Odd ele
                nums[i] = nums[i] * 2;

            minEle = min(minEle, nums[i]);

            pq.push(nums[i]);
        }

        //  Loop untill the TOP is NOT EVEN , as incase of EVEN we will divide by 2.
        while (pq.top() % 2 == 0)
        {
            int topEle = pq.top();
            pq.pop();

            diff = min(diff, topEle - minEle);
            minEle = min(minEle, topEle / 2);

            if (topEle % 2 == 0) // Even
                topEle = topEle / 2;
            pq.push(topEle);
        }

        return min(diff, pq.top() - minEle);
    }
};

/*
       INTUITION BEHIND

    1) If ODD then multiply it by 2 as every ODD element when multiplied becomes EVEN.
    2) Then PUSH into the Max - Heap and find the Minimum ele among them and Store.

 */
// @lc code=end
