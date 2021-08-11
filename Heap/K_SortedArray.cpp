
/* 
________________________________________
  - By Niharika Dutta
 Code Link :   https://www.geeksforgeeks.org/nearly-sorted-algorithm/
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
void K_Sort_MinHeap(int arr[], int n, int k)
{
    int len, count = 0, i;
    len = (n == k) ? k : k + 1;
    priority_queue<int, vector<int>, greater<int>> minHeap(arr, arr + len); // k + 1 means ----- can push 4 element inside the stack(heap)

    for (i = k + 1; i < n; i++)
    {
        arr[count++] = minHeap.top();
        minHeap.pop();
        minHeap.push(arr[i]); // insert next ele from the original array
    }

    // Remaining element of the Heap DS append into the Array
    while (minHeap.size())
    {
        arr[count++] = minHeap.top();
        minHeap.pop();
    }

    // Printing  function
    cout << "====   Sorted Array   ==== " << endl;
    for (i = 0; i < n; i++)
        cout << arr[i] << "\t";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k = 3, n;
    int arr[] = {2, 6, 3, 12, 20, 4};
    n = sizeof(arr) / sizeof(arr[0]);
    K_Sort_MinHeap(arr, n, k);

    return 0;
}