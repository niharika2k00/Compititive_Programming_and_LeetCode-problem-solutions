/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
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

// -------------------------------------------------
//           RECURSIVE METHOD
// -------------------------------------------------
bool SubsetFinder(int arr[], int sum, int len)
{
    int consider, notConsider;
    if (sum == 0)
        return true;

    if (len == 0) //  means at arr[0] when index = 0, still Sum != 0 , so assuming the remaining sum will be at arr[0]
        return (sum == arr[0]);

    // When Element is Greater than SUM  ---  Not Pick
    if (arr[len - 1] > sum)
        return SubsetFinder(arr, sum, len - 1);

    consider = SubsetFinder(arr, sum - arr[len - 1], len - 1); //  Consider
    notConsider = SubsetFinder(arr, sum, len - 1);             // Not Consider

    return consider || notConsider;
}

// -----------------------------------------------------------------------------
// MEMOIZATION '
// OR
// DYNAMIC PROGRAMMING                Time Complexity: O(2^n).
// -----------------------------------------------------------------------------
bool SubsetFinder(int arr[], int target, int len, vector<vector<int>> &Dp)
{
    int consider, notConsider;
    if (target == 0)
        return true;

    if (len == 0) //  means at arr[0] when index = 0, still Sum != 0 , so assuming the remaining target will be at arr[0]
        return (target == arr[0]);

    if (Dp[len][target] != false) // means Value present
        return Dp[len][target];

    // When Element is Greater than SUM
    if (arr[len - 1] >= target)
        return Dp[len][target] = SubsetFinder(arr, target, len - 1, Dp);

    consider = SubsetFinder(arr, target - arr[len - 1], len - 1, Dp); //  Consider
    notConsider = SubsetFinder(arr, target, len - 1, Dp);             // Not Consider

    return Dp[len][target] = consider || notConsider;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {3, 34, 4, 12, 5, 2}, sum = 9, len = sizeof(arr) / sizeof(arr[0]);
    // DP - array formed
    vector<vector<int>> Dp(len + 1, vector<int>(sum + 1, false));

    if (SubsetFinder(arr, sum, len, Dp))
        cout << "TRUE Subset is possible ";
    else
        cout << "FALSE Not posssible ";

    return 0;
}
