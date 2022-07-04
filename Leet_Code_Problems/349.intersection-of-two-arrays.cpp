/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {

        vector<int> ans;
        unordered_map<int, int> map;
        int i;

        for (i = 0; i < nums1.size(); i++)
            map.insert({nums1[i], i}); // (key , value )  --> wse are taking here kwy = VALUE bcz its unique

        for (i = 0; i < nums2.size(); i++)
        {
            if (map.find(nums2[i]) != map.end()) // find
            {
                auto it = find(ans.begin(), ans.end(), nums2[i]); //  check already exsist in the ANSWER vector
                if (it == ans.end())                              // not found
                    ans.push_back(nums2[i]);
            }
        }

        return ans;
    }
};
// @lc code=end
