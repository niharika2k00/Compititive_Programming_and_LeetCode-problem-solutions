/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.faceprep.in/tcs/tcs-codevita-questions/
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
    int len = 5, i, totalGifts = 0, sum = 0;
    // cin >> len;
    vector<int> rank{1, 2, 1, 5, 2};
    vector<int> gift(len, 1);

    // for (i = 0; i < len; i++)
    // cin >> rank[i];

    // gift[0] = 1;

    //  Rise
    for (i = 1; i < len; i++)
    {
        if (rank[i] > rank[i - 1]) // curr > prev
            gift[i] = gift[i - 1] + 1;
        else
            gift[i] = 1;
    }

    //  Fall
    for (i = len - 1; i > 0; i--)
    {
        if (rank[i] > rank[i + 1] && gift[i] < gift[i + 1]) // curr > after  &&  rank MORE gift MORE
            gift[i] = 1 + gift[i + 1];
    }

    for (i = 0; i < gift.size(); i++)
        sum += gift[i];

    cout << sum << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // test
    // {
    solve();
    // }

    return 0;
}