/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://codeforces.com/contest/1632/problem/A
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
    int len, i = 0, count = 0, flag = 0;
    cin >> len;
    string str;
    cin >> str;

    if (len == 1)
        flag = 1;

    if (len == 2 && str[0] != str[1]) // both diff -- NO palindrome
        flag = 1;

    if (flag)
        cout << "YES\n";
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