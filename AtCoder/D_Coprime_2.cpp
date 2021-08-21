/* 
________________________________________
----------------------------------------
 Author :  Niharika Dutta
 Code Link :  https://atcoder.jp/contests/abc215/tasks/abc215_d  
________________________________________
----------------------------------------
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

ll gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m, i, k, ans, count = 0;
    vector<int> vec;
    cin >> n >> m;
    for (i = 0; i < n; i++)
        cin >> vec[i];

    for (i = 1; i <= m; i++)
    {
        ans = gcd(vec[i - 1], )
    }

    return 0;
}