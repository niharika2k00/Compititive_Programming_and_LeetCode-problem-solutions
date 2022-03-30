/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codingninjas.com/codestudio/problems/triangle_1229398?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
 Time Complexity :  O (N * N)  Reason: At max, there will be (half of, due to triangle) N*N calls of recursion
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

int minimumPathSumUtil(int i, int j, vector<vector<int>> &triangle, int len, vector<vector<int>> &dp)
{
    //  Base Case (already reached the Last ROW)
    if (i == len - 1)
        return triangle[i][j];

    int down = triangle[i][j] + minimumPathSumUtil(i + 1, j, triangle, len, dp);
    int diagonal = triangle[i][j] + minimumPathSumUtil(i + 1, j + 1, triangle, len, dp);

    return dp[i][j] = min(down, diagonal);
}

int solve(vector<vector<int>> &triangle, int len)
{
    vector<vector<int>> dp(len, vector<int>(len, -1));

    return minimumPathSumUtil(0, 0, triangle, len, dp);
}

//   We can only move just down and just diagonally right. means from ( i , j )  MOVE ==>  (i + 1 , j)   &&   (i + 1 , j + 1)
//   Fixed Starting Point(0,0) and Variable ending Point
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> triangle{{1},
                                 {2, 3},
                                 {3, 6, 7},
                                 {8, 9, 6, 10}};

    int len = triangle.size();
    cout << solve(triangle, len);

    return 0;
}