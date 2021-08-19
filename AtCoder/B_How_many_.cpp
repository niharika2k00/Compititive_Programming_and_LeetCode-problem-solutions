/* 
________________________________________
----------------------------------------
 Author :  Niharika Dutta
 Code Link :  https://atcoder.jp/contests/abc214/tasks/abc214 
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

    int S, T, count = 0;
    cin >> S >> T;

    // a + b + c <= S
    // a * b * c <= T
    // therefore max val can be either S or 0

    for (int a = 0; a <= S; a++)
    {
        for (int b = 0; a + b <= S; b++)
        {
            for (int c = 0; a + b + c <= S; c++)
            {
                if (a * b * c <= T)
                    count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}