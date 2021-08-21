/* 
________________________________________
----------------------------------------
 Author :  Niharika Dutta
 Code Link :    https://atcoder.jp/contests/abc215/tasks/abc215_c
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

    string s;
    int n, i = 1;
    cin >> s;
    cin >> n;

    sort(s.begin(), s.end());

    for (int i = 1; i < n; i++)
    {
        next_permutation(s.begin(), s.end());
    }

    do
    {
        if (i == n)
            break;
        i++;
    } while (next_permutation(s.begin(), s.end()));

    cout << s << endl;

    return 0;
}