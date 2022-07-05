/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * https://leetcode.com/problems/top-k-frequent-elements/
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include <bits/stdc++.h>

class Solution
{

private:
    static bool compare(pair<int, int> &a, pair<int, int> &b) // Descending Sort
    {
        return a.second > b.second;
    }

public:
    // -----------------------
    //  Method - 1
    // -----------------------
    vector<int> sortedPriorityQueue(unordered_map<int, int> &mp, int k)
    {
        priority_queue<pair<int, int>> pq; // Max-Heap
        vector<int> result;

        for (auto it : mp)
            pq.push({it.second, it.first}); // as MaxHeap so SORT acc to the pq.first

        while (k--)
        {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }

    // -----------------------
    //   Method - 2
    // -----------------------
    vector<int> sortedHashMap(unordered_map<int, int> &mp, int k)
    {
        vector<pair<int, int>> vec;
        vector<int> result;
        int i = 0, count = 0;

        for (auto it : mp)
            vec.push_back(it);

        sort(vec.begin(), vec.end(), compare);

        for (auto pair : vec)
        {
            if (count == k)
                break;

            result.push_back(pair.first);
            count++;
        }

        return result;
    }

    // -----------------------
    //   Method - 3
    // -----------------------
    vector<int> sortedSet(unordered_map<int, int> &mp, int k)
    {
        set<pair<int, int>> Set;
        vector<int> result;

        for (auto it : mp)
            Set.insert({it.second, it.first});

        auto it = --Set.end();
        while (k--)
        {
            result.push_back(it->second);
            it--;
        }

        return result;
    }

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> hashMap; // sort by value decreasing order
        int len = nums.size(), i = 0;

        if (k == len)
            return nums;

        for (i = 0; i < len; i++)
            hashMap[nums[i]]++;

        // return sortedHashMap(hashMap, k);   //  using HashMap and Vector of Pair
        //  return sortedPriorityQueue(hashMap, k); //  using PriorityQueue MaxHeap
        return sortedSet(hashMap, k); // using Set
    }
};

// @lc code=end
