/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :
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

    vector<int> vec{0, 1, 0, 1, 0, 1, 0, 1, 0};
    int len = vec.size(), val = 1, idx = 0; // previous unique index

    for (int i = 0; i < len; i++)
    {
        if (vec[i] != val)
        {
            vec[idx] = vec[i];
            idx++;
        }
    }

    cout << idx << endl;

    vec.erase(vec.begin() + idx, vec.end());

    for (auto it : vec)
        cout << it << '\t';

    return 0;
}