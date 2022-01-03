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

void SubarrayFinder(int arr[], int n, int K)
{
    int i, currentSum = 0;
    unordered_map<int, int> mp;

    for (i = 0; i < n; i++)
    {
        currentSum = currentSum + arr[i];
        cout << i << " " << currentSum << endl;
        if (currentSum == K)
        {
            cout << "Sum found between indexes " << 0 << " to " << i << endl;
            return;
        }

        // if (currentSum - K) element is FOUND in the map
        // then take that value else by default val of any element in the map is 1
        if (mp.find(currentSum - K) != mp.end()) // if exists
        {
            cout << "Sum found between indexes " << mp[currentSum - K] + 1 << " to " << i << endl;
            return;
        }
        mp[currentSum] = i;
    }
    cout << "No subarray with given sum exists";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ********            THIS METHOD CAN DEAL WITH - ve nuber as well          ***********
    int arr[] = {8, -2, -2, -20, 7};
    int i, k = 10, n = sizeof(arr) / sizeof(arr[0]), count = 0, currentSum = 0, flag = 0;

    SubarrayFinder(arr, n, k);
    return 0;
}

/*
    Test Case :
    arr =   {10, 2, -2, -20, 10};
    sum = -10

    0 - 3  ans.
 */