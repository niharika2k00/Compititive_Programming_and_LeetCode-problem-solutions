/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :   https://www.geeksforgeeks.org/find-subarray-with-given-sum-in-array-of-integers/
 Time Complexity :  O(n)
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

//  --------------------   TWO  POINTER APPROACH  --------------------
//  Time Complexity :      O(n)
//   Space Complexity :    O(1)
void SubarrayFinder(int arr[], int n, int k)
{
    int i, currSum = 0, right = 0, left = 0;
    currSum = currSum + arr[0];
    while (currSum != k && right >= left)
    {
        if (currSum < k)
        {
            right++;
            currSum = currSum + arr[right];
        }

        else if (currSum > k)
        {
            currSum = currSum - arr[left];
            left++;
        }
    }
    cout << "Subarray found from index " << left << " to " << right << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ********            THIS METHOD CAN DEAL WITH - ve nuber as well          ***********
    int arr[] = {1, -4, 20, 3, 10, 5};
    int i, k = 16, n = sizeof(arr) / sizeof(arr[0]);

    SubarrayFinder(arr, n, k);
    return 0;
}

/*
    Test Case :
    arr =   {10, 2, -2, -20, 10};
    sum = -10

    0 - 3  ans.
 */