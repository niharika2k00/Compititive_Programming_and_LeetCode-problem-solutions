/* 
________________________________________
----------------------------------------
 Author :  Niharika Dutta
 Code Link :  https://atcoder.jp/contests/abc214/tasks/abc214_c  
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll i, n;
    cin >> n;
    ll s[n], t[n];

    // taking inputs
    for (i = 0; i < n; i++)
        cin >> s[i];

    for (i = 0; i < n; i++)
        cin >> t[i];

    // logic part
    // taking   min(its own time ,  time taken if gem passed from the prev one)
    for (int i = 1; i < n; i++)
        t[i] = min(t[i], t[i - 1] + s[i - 1]);

    t[0] = min(t[0], t[n - 1] + s[n - 1]); // appending 0 th at the end

    for (int i = 1; i < n; i++)
        t[i] = min(t[i], t[i - 1] + s[i - 1]);

    for (int i = 0; i < n; i++)
        cout << t[i] << '\n';

    return 0;
}