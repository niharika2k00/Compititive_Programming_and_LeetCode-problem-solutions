/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codechef.com/LTIME102B/problems/RPDRDNG
 Time Complexity :
________________________________________
----------------------------------------
 */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long
#define lli long long int
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

void solve()
{
    ll n, i, len, k = 0, median = 0, val;
    cin >> n;
    len = 2 * n;
    vector<ll> vec(len);
    vector<ll> num;
    map<ll, ll> hashMap;

    for (i = 0; i < len; i++)
    {
        cin >> vec[i];
        hashMap[vec[i]]++;
    }

    for (auto it : hashMap)
        num.push_back(it.first);

    // PREFIX
    while (k < n)
    {
        median = (k - 0) / 2; //  [5]    [5 6]     [5 6 7]
        val = num[median];
        if (hashMap[val] > 0)
            hashMap[val]--;
        else
        {
            cout << "-1\n";
            return;
        }
        k++;
    }

    // SUFFIX
    k = n - 1;
    while (k >= 0)
    {
        median = (n - 1 + k) / 2; //   [7]  [6 7]  [5 6 7]
        val = num[median];
        if (hashMap[val] > 0)
            hashMap[val]--;
        else
        {
            cout << "-1\n";
            return;
        }
        k--;
    }

    for (auto it : num)
        cout << it << ' ';
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    test
    {
        solve();
    }
    return 0;
}