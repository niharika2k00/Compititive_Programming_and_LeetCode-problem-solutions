/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codechef.com/COOK138C/problems/PREFPERM
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
    int n, k, previous = 0, i, j;
    cin >> n >> k;
    vector<int> vec(k), result;
    for (i = 0; i < k; i++)
        cin >> vec[i];

    for (i = 0; i < k; i++)
    {
        for (j = vec[i]; j > previous; j--)
            result.push_back(j);
        previous = vec[i];
    }

    for (auto it : result)
        cout << it << " ";

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