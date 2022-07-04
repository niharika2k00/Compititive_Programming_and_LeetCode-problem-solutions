
/* 
________________________________________
----------------------------------------
 Author :  Niharika Dutta
 Code Link :    https://atcoder.jp/contests/abc215/tasks/abc215_a
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

    string s1 = "Hello,World!";
    string s2;
    cin >> s2;

    if ((s1.compare(s2)) < 0 || (s1.compare(s2)) > 0)
        cout << "WA\n";
    else if ((s1.compare(s1)) == 0)
        cout << "AC\n";

    return 0;
}