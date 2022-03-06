/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codechef.com/UCDE2022/problems/UCODE018
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

//  You must REMOVE ONE plate/element.

void solve()
{
    int n, i, res = 0, one = 0, right = 0, start = 0, prevZeroIndex = -1;
    cin >> n;
    vector<int> vec(n);
    for (i = 0; i < n; i++)
    {
        cin >> vec[i];
        if (vec[i] == 1)
            one++;
    }

    if (one == n)
    {
        cout << n - 1 << endl;
        return;
    }

    while (right < n)
    {
        if (vec[right] == 0)
        {
            if (prevZeroIndex != -1) //  zero encounter NOT 1st time(Window Shrink)
                start = prevZeroIndex + 1;

            prevZeroIndex = right;
        }

        res = max(res, right - start + 1);
        right++;
    }

    cout << res - 1 << endl;
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