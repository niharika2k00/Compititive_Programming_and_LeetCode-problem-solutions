/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://atcoder.jp/contests/abc217/tasks/abc217_d  
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

    // We are taking SET as it arranges the element automatically sorted order
    ll l, q, i, c, x;
    set<int> set;
    cin >> l >> q;

    set.insert(0);
    set.insert(l);

    while (q--) //  Q terms
    {
        cin >> c >> x;
        if (c == 1) // Only cut the piece
            set.insert(x);
        else
        {
            auto upper = set.upper_bound(x);
            upper--;
            auto lower = set.lower_bound(x);
            cout << *lower - *upper << endl;
        }
    }
    return 0;
}

/* 
   C = 1: cut the piece at Mark x   into two.
   C = 2: Choose piece at Mark x & Print its length
​
 */