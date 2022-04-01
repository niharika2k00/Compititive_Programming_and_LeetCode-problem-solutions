
/*
______________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :    https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
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

//  NORMAL RECURSIVE APPROACH
int knapSack_Recursive(int Capacity, int weight[], int profit[], int len)
{
    int consider = 0, notConsider = 0;
    if (len == 0 || Capacity == 0)
        return 0;

    if (weight[len - 1] > Capacity)
        return knapSack_Recursive(Capacity, weight, profit, len - 1);

    else
    {
        consider = profit[len - 1] + knapSack_Recursive(Capacity - weight[len - 1], weight, profit, len - 1);
        notConsider = knapSack_Recursive(Capacity, weight, profit, len - 1);

        return max(consider, notConsider);
    }
}

//  As Capacity & Len both are only changing factor so take a 2D Array.
//   MEMOIZED - DP - APPROACH
int knapSack_Memoized(int Capacity, int len, int weight[], int profit[], vector<vector<int>> Dp)
{
    int consider = 0, notConsider = 0;
    if (len == 0 || Capacity == 0)
        return 0;

    if (weight[len - 1] > Capacity) //  Not Possible / Not Consider
        return Dp[Capacity][len] = knapSack_Memoized(Capacity, len - 1, weight, profit, Dp);

    if (Dp[Capacity][len] != -1) // means Value present
        return Dp[Capacity][len];

    // 01-Knapsack : item decreases (len - 1)   &&   Unbounded KnapSack (len) emains Same.(means we can again consider that ITEM thus len doesn't decreases)
    consider = profit[len - 1] + knapSack_Memoized(Capacity - weight[len - 1], len - 1, weight, profit, Dp);
    notConsider = knapSack_Memoized(Capacity, len - 1, weight, profit, Dp);

    return Dp[Capacity][len] = max(consider, notConsider);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int profit[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int Capacity = 35, len = sizeof(profit) / sizeof(profit[0]);

    // DP - array formed
    // memset(dp, -1, sizeof(dp));
    vector<vector<int>> Dp(Capacity + 1, vector<int>(len + 1, -1));

    cout << "Maximum profit made : " << endl;

    cout << "Memoized approach ==> " << knapSack_Memoized(Capacity, len, wt, profit, Dp) << endl;
    cout << "Normal Recursive approach ==> " << knapSack_Recursive(Capacity, wt, profit, len) << endl;

    return 0;
}