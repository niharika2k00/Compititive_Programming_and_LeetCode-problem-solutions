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

void solve()
{
    int totalSample = 0, totalRange = 0, i = 0, low = 0, high = 0, count = 0;
    vector<int> samples{345, 604, 321, 433, 704, 470, 808, 718, 517, 811};
    vector<int> res;
    int len = samples.size();
    totalSample = 10, totalRange = 2;

    while (totalRange--)
    {
        // low = 400, high = 700;
        cin >> low >> high;
        for (i = 0; i < len; i++)
        {
            if (samples[i] >= low && samples[i] <= high)
                count++;
        }
        res.push_back(count);
        count = 0;
    }

    for (auto it : res)
        cout << it << "\t";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}