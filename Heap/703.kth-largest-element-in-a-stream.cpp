/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
class KthLargest
{
public:
    // priority_queue <Type, vector<Type>, ComparisonType > min_heap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int len = 0, K = 0;

    KthLargest(int k, vector<int> &nums)
    {
        len = nums.size(), K = k;

        //  K-th Largest Element
        for (int i = 0; i < len; i++)
        {
            minHeap.push(nums[i]);

            if (minHeap.size() > k)
                minHeap.pop();
        }
    }

    int add(int val)
    {
        minHeap.push(val);

        if (minHeap.size() > K)
            minHeap.pop();

        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
