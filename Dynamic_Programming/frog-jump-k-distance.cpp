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

// If the FROG can jumps K times then what will be the minimum energy required to reach the destination.
int Helper(vector<int> &vec, int len, int K)
{
    int minEnergy = INT_MAX, j, jumps;
    if (len == 0)
        return 0;

    // J denotes number of jumps
    for (j = 1; j <= K; j++)
    {
        if (len - j >= 0)
        {
            jumps = Helper(vec, len - j, K) + abs(vec[len - j] - vec[len]);
            minEnergy = min(minEnergy, jumps);
        }
    }
    return minEnergy;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> vec{10, 40, 0, 20, 10};
    int len = vec.size(), K = 3;

    cout << Helper(vec, len, K);

    return 0;
}
