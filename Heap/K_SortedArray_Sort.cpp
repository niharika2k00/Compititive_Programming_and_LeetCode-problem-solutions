
/*
________________________________________
  - By Niharika Dutta
 Code Link :   https://www.geeksforgeeks.org/nearly-sorted-algorithm/

               https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379
________________________________________

 */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define loop1(n) for (ll i = 0; i < (n); i++)
#define loop2(n) for (ll i = 1; i <= (n); i++)
#define test  \
    ll t;     \
    cin >> t; \
    while (t--)

// Time Complexity  :  O(n log k)
//  K Sorted Array means ele @ arr[0] may shift K steps left or right to make it SORTED.
vector<int> K_Sort_MinHeap(int arr[], int len, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> res;

    for (int i = 0; i < len; i++)
    {
        minHeap.push(arr[i]);

        if (minHeap.size() > k)
        {
            int ele = minHeap.top();
            minHeap.pop();
            res.push_back(ele);
        }
    }

    // Remaining element of the Heap DS append into the Array
    while (!minHeap.empty())
    {
        int ele = minHeap.top();
        minHeap.pop();
        res.push_back(ele);
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k = 3, len;
    int arr[] = {2, 6, 3, 12, 20, 4};
    len = sizeof(arr) / sizeof(arr[0]);

    vector<int> res = K_Sort_MinHeap(arr, len, k);

    // Printing  function
    cout << "====   Sorted Array   ==== " << endl;
    for (int i = 0; i < len; i++)
        cout << res[i] << "\t";

    return 0;
}