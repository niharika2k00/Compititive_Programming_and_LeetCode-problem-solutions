/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

                https://www.youtube.com/watch?v=_rgTlyky1uQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=11

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

// Minimizes the sum of the cost of all the numbers along the path. You need to tell the minimum sum of that path.
int minPath(int row, int col, vector<vector<int>> &Dp, vector<vector<int>> &grid)
{
    if (row == 0 && col == 0)
        return grid[0][0];

    if (row < 0 || col < 0)
        return 9999999;

    if (Dp[row][col] != -1)
        return Dp[row][col];

    int up = grid[row][col] + minPath(row - 1, col, Dp, grid);
    int left = grid[row][col] + minPath(row, col - 1, Dp, grid);

    return Dp[row][col] = min(up, left);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}