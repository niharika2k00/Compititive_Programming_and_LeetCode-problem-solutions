/* 
________________________________________
  - By Niharika Dutta
 Code Link : https://codeforces.com/contest/1560/problem/A
________________________________________
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

    test
    {
        int k, i;
        cin >> k;

        vector<int> a;
        a.push_back(1);
        for (i = 1; i < 10000; i++)
        {
            if ((i % 3 != 0) && (i % 10 != 3))
                a.push_back(i);
        }

        for (i = 0; i < 10000; i++)
        {
            if (k == i)
            {
                cout << a[k] << endl;
                break;
            }
        }
    }
    return 0;
}
