
/*
______________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :    https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
 Time Complexity :  https://www.codingninjas.com/studio/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
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

//  NORMAL RECURSIVE APPROACH   TC:  2^n   Auxillary stack space: O(n)
int knapsackRecursive(int maxWeight, vector<int> &weight, vector<int> &profit, int len)
{
    int notConsider = 0, consider = 0;
    if (len == 0 || maxWeight == 0)
    {
        if (weight[0] <= maxWeight)
            return profit[0];
        return 0;
    }

    if (weight[len] >= maxWeight)
        notConsider = knapsackRecursive(maxWeight, weight, profit, len - 1);

    consider = profit[len] + knapsackRecursive(maxWeight - weight[len], weight, profit, len - 1);

    return max(consider, notConsider);
}

//  As maxWeight & Len both are only changing factor so take a 2D Array.
//   MEMOIZED - DP - APPROACH    TC: n * weight     Auxillary stack space: O(n)
int knapsackMemoized(int maxWeight, vector<int> &weight, vector<int> &profit, int len, vector<vector<int>> &dp)
{
    int notConsider = 0, consider = 0;
    if (len == 0 || maxWeight == 0)
    {
        if (weight[0] <= maxWeight)
            return profit[0];
        return 0;
    }

    if (dp[len][maxWeight] != -1)
        return dp[len][maxWeight];

    if (weight[len] >= maxWeight)
        notConsider = knapsackMemoized(maxWeight, weight, profit, len - 1, dp);

    consider = profit[len] + knapsackMemoized(maxWeight - weight[len], weight, profit, len - 1, dp);

    return dp[len][maxWeight] = max(consider, notConsider);
}

//   TABULATION APPROACH     TC: n * weight    NO Auxillary stack space ✅✅✅✅
int knapsackTabulation(int maxWeight, vector<int> &weight, vector<int> &profit, int len, vector<vector<int>> &dp)
{
    for (int W = weight[0]; W <= maxWeight; W++)
        dp[0][W] = profit[0];

    for (int idx = 1; idx < len; idx++)
    {
        for (int W = 0; W <= maxWeight; W++)
        {
            int notConsider = INT_MIN;
            if (weight[idx] > maxWeight)
                notConsider = dp[idx - 1][W];

            int consider = profit[idx] + dp[idx - 1][W - weight[idx]];

            dp[idx][W] = max(consider, notConsider);
        }
    }

    return dp[len - 1][maxWeight]; // value of the last matrix box
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> weight{1, 2, 4, 5};
    vector<int> profit{5, 4, 8, 6};
    int maxWeight = 5, len = weight.size();

    // DP - array formed
    // memset(dp, -1, sizeof(dp));
    vector<vector<int>> dp(len, vector<int>(maxWeight + 1, 0));
    cout << "Maximum profit made : " << endl;

    // cout << "Normal Recursive approach -> " << knapsackRecursive(maxWeight, weight, profit, len - 1) << endl;
    // cout << "Memoized approach -> " << knapsackMemoized(maxWeight, weight, profit, len - 1, dp) << endl;
    cout << "Tabulation approach -> " << knapsackTabulation(maxWeight, weight, profit, len, dp) << endl; // not working

    return 0;
}
