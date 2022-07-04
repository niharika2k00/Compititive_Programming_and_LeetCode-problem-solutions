/* 
________________________________________
----------------------------------------
 Author :  Niharika Dutta
 Code Link :    https://atcoder.jp/contests/abc215/tasks/abc215_b
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

    ll int n, ans, i;
    cin >> n;

    if (n == 1)
        cout << "0" << endl;
    else
    {
        ans = log2(n) / log2(2);
        cout << floor(log2((long double)n)) << '\n'; // correct ans according to editorial as my ans was having more precisions than 64-bit floating point decimal
        cout << ans << endl;
    }

    // OR  \\

    for (i = 0; i <= 10000000; i++)
    {
        ans = pow(2, i);
        if (ans > n)
        {
            cout << i - 1 << endl;
            break;
        }
    }
    return 0;
}