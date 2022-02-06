/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://codeforces.com/contest/1632/problem/B
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

//   Video :  https://www.youtube.com/watch?v=fnSWZlqWp4o
void solve()
{
    int len, i;
    cin >> len;

    //  Max bit at the Last
    int maxLSB = log2(len - 1);
    maxLSB = pow(2, maxLSB);

    // for (i = 1; i < maxLSB; i++)
    for (i = maxLSB - 1; i >= 0; i--)
        cout << i << " ";

    // cout << "0 ";

    for (i = maxLSB; i < len; i++)
        cout << i << " ";

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