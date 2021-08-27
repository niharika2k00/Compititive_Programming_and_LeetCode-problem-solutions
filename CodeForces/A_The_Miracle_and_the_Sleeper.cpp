/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :    https://codeforces.com/contest/1562/problem/A
 Time Complexity :  
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

    /* 
               r >= a >= b >= l
               26 >= a >= b >= 8

       Find the largest possible value of amodb over all pairs (a,b) of integers for which   r >= a >= b >= l .
    */

    test
    {
        ll l, r, ans, k;
        cin >> l >> r;

        k = ceil(r / 2) + 1;

        if (l == r)
            cout << "0\n";
        else if (k < l) // num < min
            cout << r % l << endl;
        else
            cout << r % k << endl;
    }
    return 0;
}