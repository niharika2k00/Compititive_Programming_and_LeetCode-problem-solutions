/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codechef.com/LTIME105C/problems/PLPROCESS
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
    int n, i, minTime = INT_MAX, sum = 0, res = 0, leftSum = 0, rightSum = 0, maxBetweenTwoProcessor = 0;
    cin >> n;
    vector<int> vec(n);
    vector<int> prefixSum(n, 0);

    for (i = 0; i < n; i++)
    {
        cin >> vec[i];
        sum = sum + vec[i];
    }

    prefixSum[0] = vec[0];
    for (i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + vec[i];

    //   Logic
    for (i = 0; i < n; i++)
    {
        leftSum = prefixSum[i];
        rightSum = sum - prefixSum[i];

        maxBetweenTwoProcessor = max(leftSum, rightSum); //  if one completes at 4 mins and other at 5 mins ,then take 5 mins to Complete the whole task
        minTime = min(minTime, maxBetweenTwoProcessor);
    }

    cout << minTime << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    test
    {
        solve();
    }

    return 0;
}