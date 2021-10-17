
/* 
________________________________________
  - By Niharika Dutta
 Code Link : 
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {1, 1, 1, 2, 2, 3, 4};
    int i, size = sizeof(arr) / sizeof(arr[0]);
    unordered_map<int, int> map;
    priority_queue<pair<int, int>> maxHeap; // Heap taking PAIR

    for (i = 0; i < size; i++)
        map[arr[i]]++;

    for (auto it = map.begin(); it != map.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
        maxHeap.push(make_pair(it->first, it->second));
    }

    while (!maxHeap.empty())
    {
        cout << maxHeap.top().first << "\t";
        // cout << maxHeap.top().second << " " << maxHeap.top().first << endl;
        maxHeap.pop();
    }

    return 0;
}