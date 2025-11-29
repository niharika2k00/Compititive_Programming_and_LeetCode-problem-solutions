
/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codingninjas.com/codestudio/problems/k-max-sum-combinations_975322?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
 Time Complexity :
________________________________________
----------------------------------------
 */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int len, int k)
{
    //  BRUTE FORCE METHOD
    //  Time-Complexity : O(n^2)
    //  Space Complexity :  O(n)
    priority_queue<int, vector<int, int>> maxHeap;
    vector<int> res;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
            maxHeap.push(a[i] + b[j]);
    }

    while (k--)
    {
        int ele = maxHeap.top();
        maxHeap.pop();
        res.push_back(ele);
    }

    return res;

    // ------------------------------------------------------------------------------
    //  OPTIMIZED APPROACH
    //  Time-Complexity : O(nlogn)
    //  Space Complexity :  O(n)

    // Reverse sort - max ele @begin
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    priority_queue<pair<int, pair<int, int>>> maxHeap; //  {sum , {i , j}}
    vector<int> result;
    set<pair<int, int>> mySet; // for storing the unique pairs (i,j)

    maxHeap.push({a[0] + b[0], {0, 0}}); // store the initial sum
    mySet.insert({0, 0});

    while (k--)
    {
        pair<int, pair<int, int>> top = maxHeap.top();
        maxHeap.pop();
        int sum = top.first;
        int i = top.second.first;
        int j = top.second.second;

        result.push_back(sum);

        // Search in the set whether pair exist previously or not.Then gradually increment i , j.
        if (mySet.find({i + 1, j}) == mySet.end())
        {
            maxHeap.push({a[i + 1] + b[j], {i + 1, j}});
            mySet.insert({i + 1, j});
        }

        if (mySet.find({i, j + 1}) == mySet.end())
        {
            maxHeap.push({a[i] + b[j + 1], {i, j + 1}});
            mySet.insert({i, j + 1});
        }
    }

    return result;
}

// https://placewit.medium.com/k-max-sum-combinations-2c6d67a3acb
