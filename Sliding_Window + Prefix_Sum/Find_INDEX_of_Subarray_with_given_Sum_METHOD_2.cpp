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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ********            THIS METHOD CAN DEAL WITH - ve nuber as well          ***********
    int arr[] = {10, 2, -2, -20, 10};
    int i, k = -10, n = sizeof(arr) / sizeof(arr[0]), count = 0, currentSum = 0, flag = 0;

    unordered_map<int, int> mp;

    for (i = 0; i < n; i++)
    {
        currentSum = currentSum + arr[i];
        if (currentSum == k)
            count++;

        // if (currentSum - k) element is FOUND in the map
        // then take that value else by default val of any element in the map is 1
        if (mp.find(currentSum - k) != mp.end())
        {
            cout << "Sum found between indexes " << 0 << " to " << i << endl;
            flag = 1;
        }

        mp[currentSum] = 1;
    }

    if (!flag)
        cout << "No Subarray exsist with the given Sum " << endl;

    return 0;
}