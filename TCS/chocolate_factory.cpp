/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :    https://prepinsta.com/tcs-nqt/placement-papers/coding-questions/
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

    vector<int> vec{6, 0, 1, 8, 0, 2};
    int len = vec.size(), idx = 0, count = 0;

    for (int i = 0; i < len; i++)
    {
        if (vec[i] != 0)
        {
            vec[idx] = vec[i];
            idx++;
        }
        else
            count++;
    }

    vec.erase(vec.begin() + idx, vec.end());

    while (count--)
        vec.push_back(0);

    for (auto it : vec)
        cout << it << "\t";

    return 0;
}