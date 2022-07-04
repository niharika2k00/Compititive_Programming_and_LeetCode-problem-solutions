
//   LINKS ::   https://codeforces.com/contest/1555/problem/A
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
        unsigned ll n, ans, flag = 0;
        cin >> n;

        if (n < 6)
        {
            cout << "15" << endl;
            flag = 1;
        }
        if (n % 2 != 0) // odd -- add 1 to make it even
            n = n + 1;

        ans = (5 * n) / 2;

        if (!flag)
            cout << ans << endl;
    }

    return 0;
}