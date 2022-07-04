/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 *
 * https://leetcode.com/problems/third-maximum-number/
 *
 */

// @lc code=start
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        //  Time Complexity :   O(nlogn)
        //  Space Complexity :  O(1)
        int len = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        nums.erase(unique(nums.begin(), nums.end()), nums.end()); // filter the unique elements

        len = nums.size(); // modified

        if (len == 1 || len == 2)
            return nums[0];

        return nums[2];

        //  Time Complexity :   O(nlogn)
        //  Space Complexity :  O(1)
        int len = nums.size(), count = 1;

        sort(nums.begin(), nums.end(), greater<int>());

        for (int i = 1; i < len; i++)
        {
            if (nums[i - 1] > nums[i])
                count++;

            if (count == 3)
                return nums[i];
        }

        return nums[0];

        // Using Priority Queue || Heap
        //  Time Complexity :   O(nlogn)
        //  Space Complexity :  O(1)
        int len = nums.size(), count = 1, res = 0, k = 3;
        set<int> st;
        for (auto it : nums)
            st.insert(it);

        if (st.size() < 3) // 1  or  2
            return *max_element(st.begin(), st.end());

        priority_queue<int, vector<int>> pq(st.begin(), st.end()); //  Max Heap

        while (k--) // 3rd largest
        {
            res = pq.top();
            pq.pop();
        }

        return res;
    }
};
// @lc code=end

/*
   Test Case :
 ----------------
[3,2,1]
[1,2]
[2,2,3,1]
[1,1,2]

 */