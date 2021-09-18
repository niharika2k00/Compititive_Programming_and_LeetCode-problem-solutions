/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://atcoder.jp/contests/abc219/tasks/abc219_c  
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

    string x, s;
    int i, n;

    cin >> n;
    cin >> x;

    unordered_map<char, int> hashMap;
    vector<string> s(n);

    for (i = 0; i < n; i++)
        cin >> s[i];

    // Storing in the Hash-Map
    for (i = 0; i < n; i++)
        hashMap[s[i]] = i;

    return 0;
}