/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        int len = stones.size(), i;
        priority_queue<int> pq;

        for (i = 0; i < len; i++)
            pq.push(stones[i]);

        if (len == 1)
            return stones[0];

        while (!pq.empty() && pq.size() > 1)
        {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if (x == y)
                continue;

            pq.push(y - x);
        }

        return pq.empty() ? 0 : pq.top();
    }
};
// @lc code=end
