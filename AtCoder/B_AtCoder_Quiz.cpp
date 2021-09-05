/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://atcoder.jp/contests/abc217/tasks/abc217_b  
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

    // ABC, ARC, AGC, and AHC.

    string a, b, c;
    cin >> a >> b >> c;

    if ((a == "ABC" || a == "ARC" || a == "AGC") && (b == "ABC" || b == "ARC" || b == "AGC") && (c == "ABC" || c == "ARC" || c == "AGC"))
        cout << "AHC\n";

    else if ((a == "ABC" || a == "ARC" || a == "AHC") && (b == "ABC" || b == "ARC" || b == "AHC") && (c == "ABC" || c == "ARC" || c == "AHC"))
        cout << "AGC\n";

    else if ((a == "ABC" || a == "AGC" || a == "AHC") && (b == "ABC" || b == "AGC" || b == "AHC") && (c == "ABC" || c == "AGC" || c == "AHC"))
        cout << "ARC\n";

    else
        cout << "ABC\n";

    return 0;
}