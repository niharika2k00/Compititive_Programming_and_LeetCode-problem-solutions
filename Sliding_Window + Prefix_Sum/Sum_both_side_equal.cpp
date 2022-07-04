/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://leetcode.com/contest/biweekly-contest-60/problems/find-the-middle-index-in-array/
          https://www.geeksforgeeks.org/find-element-array-sum-left-array-equal-sum-right-array/
 Time Complexity :
________________________________________
----------------------------------------
 */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long
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

//  Time Complexity : O(n)
//  Space Complexity :  O(1)
int findElement(int arr[], int n)
{
    if (n == 1)
        return 0;

    int sum, i, prefixSum = 0, ans = -1;
    sum = accumulate(arr, arr + n, 0);
    for (i = 0; i < n; i++)
    {
        if (prefixSum == sum - (arr[i] + prefixSum))
        {
            ans = i;
            break;
        }
        prefixSum += arr[i];
    }
    return ans;
}

//  Time Complexity : O(n)
//  Space Complexity :  O(n)
int findEquilibrium(int arr[], int len)
{
    // Base Case
    if (len == 1) //  True
        return 0;

    int i, ans = -1, rightSum = 0, leftSum = 0, totalSum = accumulate(arr, arr + len, 0);
    vector<int> prefixSum(len, 0);
    prefixSum[0] = arr[0];

    for (i = 1; i < len; i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i];

    for (i = 0; i < len; i++)
    {
        leftSum = prefixSum[i] - arr[i];
        rightSum = totalSum - prefixSum[i];

        if (leftSum == rightSum)
            return i;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {2, 3, -1, 8, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findElement(arr, n) << endl;
    int result = findEquilibrium(arr, n);
    if (result >= 0)
        cout << "Equilibrium Point at Index " << result << endl;
    else
        cout << "Not Found!" << endl;

    return 0;
}

/*
TEST CASES ::

[0 0 0 0]
ans : 0

[0 4]
ans : 1

[1 -1 4]
ans : 2

[2 3 -1 8 4]
ans : 3
 */
