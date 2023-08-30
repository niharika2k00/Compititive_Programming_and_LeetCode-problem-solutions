
// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution
{
public:
  // Recursive Method
  // int helper1 (vector<int>&arr, int len, int i, int prevIdx){
  //     int consider = 0, notConsider = 0;
  //     if(i == len)
  //         return 0;

  //     notConsider = helper1(arr, len, i+1, prevIdx);

  //     if(prevIdx == -1 || arr[i] > arr[prevIdx]) // means increasing as curr > prev
  //         consider = 1 + helper1(arr, len, i+1, i);

  //     return max(consider, notConsider);
  // }

  // Memoized Method
  int helper2(vector<int> &arr, int len, int i, int prevIdx, vector<vector<int>> &dp)
  {
    int consider = 0, notConsider = 0;
    if (i == len)
      return 0;

    if (dp[i][prevIdx + 1] != -1)
      return dp[i][prevIdx + 1];

    notConsider = helper2(arr, len, i + 1, prevIdx, dp);

    if (prevIdx == -1 || arr[i] > arr[prevIdx]) // means increasing as curr > prev
      consider = 1 + helper2(arr, len, i + 1, i, dp);

    return dp[i][prevIdx + 1] = max(consider, notConsider);
  }

  int lengthOfLIS(vector<int> &arr)
  {
    int len = arr.size();
    vector<vector<int>> dp(len, vector<int>(len + 1, -1)); // coordinate change for which -1 's thing is stored in 0th index

    return helper2(arr, len, 0, -1, dp);
  }

/*
  COORDINATE SHIFT...HOW ??

  Idx -> 0 to n-1 = n size arr will suffice
  PrevIdx -> -1 to n-1 so
 */


  void tabulation(){
    vector<vector<int>> dp(n+1, 0);
    for (int idx=0; idx<n ; idx++){
      for(int prevIdx=-1; prevIdx<n ; prevIdx++){
        
      }
    }
  }
};
