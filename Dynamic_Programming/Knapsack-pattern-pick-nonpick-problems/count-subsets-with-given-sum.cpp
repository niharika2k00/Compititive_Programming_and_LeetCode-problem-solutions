/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
              https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/
              https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/

              https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
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

int Subset_CountFinder(vector<int> &arr, int len, int target, vector<vector<int>> &dp)
{
    int consider = 0, notConsider = 0;
    // Base Case
    if (target == 0) // sum of the subset == target
        return 1;

    if (len == 0) // If the element is equal to the target we return 1 else we return 0.
        return arr[0] == target;

    //  Case when the array having element 0
    if (len == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0)
            return 1;
    }

    if (dp[len][target] != -1)
        return dp[len][target];

    if (arr[len] <= target)
        consider = Subset_CountFinder(arr, len - 1, target - arr[len], dp); //  Consider OR  Pick

    notConsider = Subset_CountFinder(arr, len - 1, target, dp); // Not Consider

    return dp[len][target] = consider + notConsider;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> vec{1, 2, 2, 3};
    int target = 3, len = vec.size(), count = 0; // (1,2)  (1,2)  (3)

    vector<vector<int>> dp(len, vector<int>(target + 1, -1));
    count = Subset_CountFinder(vec, len - 1, target, dp);

    cout << "Total Subset Present with the given Sum = " << count << endl;
    return 0;
}

// Draw a Recursive Tree for better understanding Refer to Copy.
/*
       Test Case
       { 3 0 3 3 } , sum = 6
       ans : 5

       {}
*/
