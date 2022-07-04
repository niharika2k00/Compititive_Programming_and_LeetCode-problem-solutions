/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://atcoder.jp/contests/abc223/tasks/abc223_b  
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

    // string r = s1.substr(startingIndex ,  length);
    string s = "aaba";
    int i, len = s.length();
    vector<string> V(len);

    for (i = 0; i < len; i++)
        V[i] = s.substr(i, len - i) + s.substr(0, i);

    cout << *min_element(V.begin(), V.end()) << endl;
    cout << *max_element(V.begin(), V.end()) << endl;

    return 0;
}