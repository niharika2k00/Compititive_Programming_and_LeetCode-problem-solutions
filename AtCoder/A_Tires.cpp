/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://atcoder.jp/contests/abc224/tasks/abc224_a
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

    string s;
    cin >> s;
    int len = s.length();

    if ((len >= 3 && (s.substr(len - 3, 3) == "ist")) || (s == "ist"))
        cout << "ist" << endl;
    else if ((s.substr(len - 2, 2) == "er") || (s == "er"))
        cout << "er" << endl;

    return 0;
}