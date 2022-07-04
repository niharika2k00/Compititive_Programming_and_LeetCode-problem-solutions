
//   LINKS ::   https://codeforces.com/contest/1557/problem/A
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

    test
    {
        ll int n, i, first, sum = 0;

        double total;
        cin >> n;
        vector<int> arr(n);

        for (i = 0; i < n; i++)
            cin >> arr[i];

        // auto it = max_element(arr.begin(), arr.end());
        // cout << *it;
        // first = *it;

        sort(arr.begin(), arr.end());
        first = arr[n - 1];

        arr.pop_back(); // n-1 elements present
        for (i = 0; i < arr.size(); i++)
            sum = sum + arr[i];

        total = (double)sum / (n - 1) + (double)first;
        cout << fixed << setprecision(9) << total << endl;
    }
    return 0;
}