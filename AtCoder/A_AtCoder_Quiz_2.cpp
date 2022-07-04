/* 
________________________________________
---------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://atcoder.jp/contests/abc219/tasks/abc219_a  
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, ans = 0;
    cin >> x;

    if (x >= 0 && x < 40)
        cout << (40 - x) << endl;

    else if (x >= 40 && x < 70)
        cout << (70 - x) << endl;

    else if (x >= 70 && x < 90)
        cout << (90 - x) << endl;

    else if (x >= 90)
        cout
            << "expert\n"
            << endl;

    return 0;
}