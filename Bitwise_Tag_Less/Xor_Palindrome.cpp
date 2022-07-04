/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codechef.com/FEB222C/problems/XORPAL
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
    int i, len, zero = 0, one = 0;
    cin >> len;
    string str;
    cin >> str;

    for (i = 0; i < len; i++)
    {
        if (str[i] == '0')
            zero++;
        else
            one++;
    }

    if (len % 2 != 0) // means length ODD
    {
        cout << "YES\n";
        return;
    }

    //  length EVEN
    //  YES   --->   all zero , all one , both one & zero exist even number of times.
    if (zero == one || zero == len || one == len || (zero % 2 == 0 && one % 2 == 0))
    {
        cout << "YES\n";
        return;
    }

    else
        cout << "NO\n";
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