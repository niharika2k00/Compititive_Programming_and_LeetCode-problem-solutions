/*
______________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :    https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
 Time Complexity :  Time Complexity: O(2^n).
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

//  As Capacity & Len both are only changing factor so take a 2D Array.
int knapSack(int Capacity, int len, int weight[], int profit[], vector<vector<int>> Dp)
{
    int consider = 0, notConsider = 0;
    if (len == 0 || Capacity == 0)
        return 0;

    if (weight[len - 1] > Capacity) //  Not Possible / Not Consider
        return Dp[Capacity][len] = knapSack(Capacity, len - 1, weight, profit, Dp);

    if (Dp[Capacity][len] != -1) // means Value present
        return Dp[Capacity][len];

    else
    {
        // 01-Knapsack : item decreases (len - 1)   &&   Unbounded KnapSack remains Same.(means we can again consider that ITEM thus len doesn't decreases)
        consider = profit[len - 1] + knapSack(Capacity - weight[len - 1], len, weight, profit, Dp);
        notConsider = knapSack(Capacity, len - 1, weight, profit, Dp);

        return Dp[Capacity][len] = max(consider, notConsider);
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int profit[] = {100, 60, 120};
    int wt[] = {10, 20, 30};
    int Capacity = 35, len = sizeof(profit) / sizeof(profit[0]);

    // DP - array formed
    vector<vector<int>> Dp(Capacity + 1, vector<int>(len + 1, -1));
    // memset(dp, -1, sizeof(dp));

    cout << "Maximum profit made : " << knapSack(Capacity, len, wt, profit, Dp);

    return 0;
}

/*
      We create a 2D vector containing "n" elements each having the value "vector<int> (m, 0)".
       "vector<int> (m, 0)" means a vector having "m" elements each of value "0".

        vector<vector<int>> vec( 3 , vector<int> (4, 0));

                0 0 0 0
                0 0 0 0
                0 0 0 0

 */