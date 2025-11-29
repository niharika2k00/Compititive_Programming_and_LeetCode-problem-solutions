
/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :
 Time Complexity :   O(2^n) <-- Exponenetial TC using Recursion
                     O(n * sum)   <-- using DP + Recursion
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

int MinimizeDiff(vector<vector<int>> Dp, vector<int> vec, int len, int totalSum, int subArr1Sum)
{
    int consider, notConsider;
    // Base Case            when iterator reaches the first Index  &&   LEN  =  0 arr has only 1 element
    if (len == 0)
        return abs(totalSum - 2 * subArr1Sum);

    if (Dp[len][subArr1Sum] != -1) //  not -1 means it has value
        return Dp[len][subArr1Sum];

    consider = MinimizeDiff(Dp, vec, len - 1, totalSum, subArr1Sum + vec[len - 1]);
    notConsider = MinimizeDiff(Dp, vec, len - 1, totalSum, subArr1Sum);

    return Dp[len][subArr1Sum] = min(consider, notConsider);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> vec{2, 8};
    int len = vec.size(), totalSum = accumulate(vec.begin(), vec.end(), 0);
    vector<vector<int>> Dp(len + 1, vector<int>(1000, -1));

    cout << " \nMinimum diff between 2 Subarray :=> " << MinimizeDiff(Dp, vec, len, totalSum, 0) << endl;

    return 0;
}

/*
        ::  Test Case  ::
     -------------------------
Input:  arr[] = {1, 6, 11, 5}
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12
Subset2 = {11}, sum of Subset2 = 11


   Explanations :
   TotalSum = 23
   subarr1(S1) + subarr2(S2) = totalSum(TS)    (if S2 sum is more)

   Difference :
   S2 -  S1 =  Minimize Diff
   (TS - S1) - S1  = Minimize Diff

   [ TS - 2S1 ]= Minimize Diff

 */