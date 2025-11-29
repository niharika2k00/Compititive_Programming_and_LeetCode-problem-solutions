
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

typedef pair<int, int> pint;

// find the  K  closest value from the X number in the given array

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {5, 16, 7, 8, 9};
    int k = 3, x = 7, i, size = sizeof(arr) / sizeof(arr[0]), diff;

    // priority_queue<pair<int, int>> maxHeap;
    priority_queue<pint, vector<pint>, greater<pint>> maxHeap;

    // --------   ALGORITHM  -------
    /*
          Take a max heap of Pair Type
          key pair.first =  will be the differene of the arr[i] & X     ,    pair.second =  arr[i]
     */

    for (i = 0; i < size; i++)
    {
        diff = abs(arr[i] - x);
        maxHeap.push(make_pair(diff, arr[i]));
    }

    while (k--)
    {
        cout << maxHeap.top().second << "\t";
        maxHeap.pop();
    }

     return 0;
}