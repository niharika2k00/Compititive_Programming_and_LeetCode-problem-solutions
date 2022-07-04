

// #include <bits/stdc++.h>

// https://leetcode.com/problems/find-the-difference-of-two-arrays/

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        //  distinct/unique element
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<vector<int>> result(2);

        for (auto &it : set1)
        {
            if (set2.find(it) == set2.end()) // not found
                result[0].push_back(it);
        }

        for (auto &it : set2)
        {
            if (set1.find(it) == set1.end()) // not found
                result[1].push_back(it);
        }

        return result;
    }
};