/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :   https://atcoder.jp/contests/abc219/tasks/abc219_b 
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

    string s1, s2, s3, T;
    string result = "";
    cin >> s1 >> s2 >> s3 >> T;
    int i = 0;

    for (i = 0; i < T.size(); i++)
    {
        if (T[i] == '1')
            result = result + s1;

        if (T[i] == '2')
            result = result + s2;

        if (T[i] == '3')
            result = result + s3;
    }

    for (auto i : result)
        cout << i;

    return 0;
}