
/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?leftPanelTab=0
 Time Complexity :
________________________________________
----------------------------------------
 */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>> &kArr, int k)
{
    // Sort in ASC Order so take Min-Heap     kArrays = [[] [] []]
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> res;

    for (int i = 0; i < k; i++)
    {
        // Loop runs for size of subarray times
        for (int j = 0; j < kArr[i].size(); j++)
            minHeap.push(kArr[i][j]);
    }

    while (!minHeap.empty())
    {
        int ele = minHeap.top();
        minHeap.pop();
        res.push_back(ele);
    }

    return res;
}

/*
         Example :
         2 arrays
         3  size1
         3 5 9
         4  size2
         1 2 3 8

    ANS :  [1 2 3 3 5 8 9]
 */