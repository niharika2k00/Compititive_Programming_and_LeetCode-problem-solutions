/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 *
 * https://leetcode.com/problems/top-k-frequent-words/
 *
 */

// @lc code=start
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        //  Time Complexity :  O(n)
        //  Space Complexity :  O(n)

        int len = words.size(), count = 0;
        map<string, int> hashMap;                     // taking map instead of unordered_map for LEXICOGRAPHICALLY SORT
        multimap<int, string, greater<int>> multiMap; //  DESC sort by 1st Key
        vector<string> result;

        for (int i = 0; i < len; i++)
            hashMap[words[i]]++;

        for (auto it : hashMap)
            multiMap.insert({it.second, it.first}); // [count , string]

        for (auto it : multiMap)
        {
            result.push_back(it.second);
            count++;

            if (count == k)
                break;
        }

        return result;
    }
};
// @lc code=end
