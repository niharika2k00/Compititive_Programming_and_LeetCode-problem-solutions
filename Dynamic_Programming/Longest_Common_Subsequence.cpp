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

//  Recursive Approach
int LCS_Recursive(string x, string y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;

    if (x[m - 1] == y[n - 1]) // check last character
        return 1 + LCS_Recursive(x, y, m - 1, n - 1);

    else
        return max(LCS_Recursive(x, y, m - 1, n), LCS_Recursive(x, y, m, n - 1));
}

//  Memoization - Dp Approach  (Top - Down)
int LCS_Memoized(string x, string y, int m, int n, vector<vector<int>> Dp)
{
    if (m == 0 || n == 0)
        return 0;

    if (Dp[m][n] != -1)
        return Dp[m][n];

    if (x[m - 1] == y[n - 1]) // check last character
        return Dp[m][n] = 1 + LCS_Memoized(x, y, m - 1, n - 1, Dp);

    else
        return Dp[m][n] = max(LCS_Memoized(x, y, m - 1, n, Dp), LCS_Memoized(x, y, m, n - 1, Dp));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string x = "abcdgh", y = "abedfh";
    int m = x.length(), n = y.length();

    //  M  x  N  Dp matrix  initialises to -1
    vector<vector<int>> Dp(m + 1, vector<int>(n + 1, -1));

    int lenRecursiveWay = LCS_Recursive(x, y, m, n);
    int lenMemoizedWay = LCS_Memoized(x, y, m, n, Dp);

    cout << "Length of the Longest Common Subsequence: " << lenMemoizedWay << endl;

    return 0;
}