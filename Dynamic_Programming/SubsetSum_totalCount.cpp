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

int Subset_CountFinder(int arr[], int start, int sum, int len)
{
    int consider, notConsider;

    // Base Case
    if (start == len && sum == 0 || len == 0 && sum == 0) // when full traversed  | OR |  Array Size = 0.
        return 1;

    if (start == len && sum != 0 || len == 0 && sum == 0)
        return 0;

    // When arr Element is Greater than SUM .
    if (arr[start] > sum)
        return Subset_CountFinder(arr, start + 1, sum, len); //  Not Consider

    consider = Subset_CountFinder(arr, start + 1, sum - arr[start], len); //  Consider
    notConsider = Subset_CountFinder(arr, start + 1, sum, len);           // Not Consider

    /* if (len == 0 && sum == 0)
        return 1;

    if (len == 0 && sum != 0)
        return 0;

    // When arr Element is Greater than SUM .
    if (arr[len - 1] > sum)
        return Subset_CountFinder(arr, sum, len - 1); //  Not Consider

    consider = Subset_CountFinder(arr, sum - arr[len - 1], len - 1); //  Consider
    notConsider = Subset_CountFinder(arr, sum, len - 1);             // Not Consider */

    return consider + notConsider;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {-10, 20, -2, 2}, sum = -10, len = sizeof(arr) / sizeof(arr[0]), count = 0;
    count = Subset_CountFinder(arr, 0, sum, len);
    cout << "Total Subset Present with the given Sum = " << count << endl;
    return 0;
}

// Draw a Recursive Tree for better understanding Refer to Copy.

/*
       Test Case
       { 3 0 3 3 } , sum = 6
       ans : 6

       {}

 */