/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * https://leetcode.com/problems/k-diff-pairs-in-an-array/
 *
 * [532] K-diff Pairs in an Array
 */

// @lc code=start
class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        int i, ans = 0, len = nums.size();
        unordered_map<int, int> hashMap;

        //  Initialization
        for (i = 0; i < len; i++)
            hashMap[nums[i]]++;

        //  Pair Finding
        for (auto it : hashMap)
        {
            //  it.first alreasy exist so now cheking whether (it.first + K) also esist or NOT.
            if ((k > 0 && hashMap.find(it.first + k) != hashMap.end()) || k == 0 && hashMap[it.first] > 1)
                ans++;
        }

        return ans;
    }
};

/*
     If  K > 0 ,
                 check whether (ele + K) is present in the MAP.
     Else If  K == 0 ,
                  check whether (ele + K) exsist  > 1
*/
// @lc code=end
