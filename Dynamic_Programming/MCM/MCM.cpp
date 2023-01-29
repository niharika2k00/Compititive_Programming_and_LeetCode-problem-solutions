
// https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication_975344?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int mcm(vector<int> &arr, int i, int j)
{
  if (i >= j)
    return 0;

  int mini = 1e9;
  for (int k = i; k < j; k++)
  {
    int steps = (arr[i - 1] * arr[k] * arr[j]) + mcm(arr, i, k) + mcm(arr, k + 1, j);

    if (steps < mini)
      mini = steps;
  }

  return mini;
}

int mcmMemoised(vector<int> &arr, vector<vector<int>> &dp, int i, int j)
{
  if (i >= j)
    return 0;

  if (dp[i][j] != -1)
    return dp[i][j];

  int mini = 1e9;
  for (int k = i; k < j; k++)
  {
    int steps = (arr[i - 1] * arr[k] * arr[j]) + mcm(arr, dp, i, k) + mcm(arr, dp, k + 1, j);

    if (steps < mini)
      mini = steps;
  }

  return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int n)
{
  // vector<vector<int>> dp(n, vector<int>(n, -1));
  // int res = mcmMemoised(arr, dp, 1, n - 1);

  int res = mcm(arr, 1, n - 1);

  return res;
}
