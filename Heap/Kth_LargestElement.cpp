
//   LINKS :   : https://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>

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

    vector<int> vec = {7, 4, 6, 3, 9, 1};
    int k = 2;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    // for (auto i = vec.begin(); i != vec.end(); i++)
    for (int i = 0; i < vec.size(); i++)
    {
        minHeap.push(vec[i]);
        if (minHeap.size() > k)
            minHeap.pop();
    }

    cout << "The second largest element is " << minHeap.top() << endl;

    return 0;
}