/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

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

/*
        Given a ‘N’ * ’M’ maze with obstacles, count and return the number of paths to reach the right-bottom cell from the top-left cell.
        A cell in the given maze has a value -1 if it is a BLOCKAGE or DEAD - END, else 0. From a given cell, we are allowed to move to cells (i+1, j) and (i, j+1) only.
 */

int mod = (int)(1e9 + 7);

int path(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &Dp)
{
    //  Base Case
    if (row == 0 && col == 0) // means already reached [0,0] thus Increament +1.
        return 1;

    if (row >= 0 && col >= 0 && matrix[row][col] == -1) // as  [-1  ===  BLOCKAGE ] , thus don't count that Path
        return 0;

    if (Dp[row][col] == -1)
        return Dp[row][col];

    if (row < 0 || col < 0)
        return 0;

    int up = path(row - 1, col);
    int left = path(row, col - 1);

    return Dp[row][col] = (up + left) % mod;
}

int minSumPath(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();

    //     cout << row << " " << col << endl;
    vector<vector<int>> Dp(row, vector<int>(col, -1));
    return minPath(row - 1, col - 1, Dp, grid);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    minSumPath();

    return 0;
}