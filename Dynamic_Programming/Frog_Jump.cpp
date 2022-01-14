/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
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

// Either can Jump 1 step or 2 step
int Helper(int len, vector<int> &h, vector<int> &dp)
{
    int twoStep = INT_MAX, oneStep;
    if (len == 0)
        return 0;

    if (dp[len] != -1) // means value exsist Memoization
        return dp[len];

    if (len - 2 >= 0)
        twoStep = abs(h[len] - h[len - 2]) + Helper(len - 2, h, dp);
    oneStep = abs(h[len] - h[len - 1]) + Helper(len - 1, h, dp);

    return dp[len] = min(twoStep, oneStep);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Write your code here.
    vector<int> heights{10, 20, 30, 10};
    int len = heights.size();

    vector<int> dp(len + 1, -1);
    cout << Helper(len - 1, heights, dp);

    return 0;
}