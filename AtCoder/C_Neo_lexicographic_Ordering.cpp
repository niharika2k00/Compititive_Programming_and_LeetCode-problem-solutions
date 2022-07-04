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
#include <stdio.h>
#include <bits/stdc++.h>
#include <sstream>

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

unordered_map<char, int> hashMap;

bool compare(string x, string y)
{
    for (int i = 0; i < min(x.size(), y.size()); i++)
    {
        if (hashMap[x[i]] == hashMap[y[i]])
            continue;
        return hashMap[x[i]] < hashMap[y[i]];
    }

    return x.size() < y.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string x;
    int i, n;

    cin >> x;
    cin >> n;

    vector<string> s(n);

    for (i = 0; i < n; i++)
        cin >> s[i];

    // Storing in the Hash-Map
    for (i = 0; i < x.size(); i++)
        hashMap[x[i]] = i;

    sort(s.begin(), s.end(), compare); // Comparator Function

    for (i = 0; i < n; i++)
        cout << s[i] << "\n";

    return 0;
}
