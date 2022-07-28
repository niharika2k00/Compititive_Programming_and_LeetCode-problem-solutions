/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :   https://leetcode.com/problems/peak-index-in-a-mountain-array/
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

// ----------------------------------------
//     Binary Search   O(n logn)
// ----------------------------------------
int peakElement_Finder(int *arr, int len)
{
    int high = len - 1, low = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] < arr[mid + 1]) //  means right e big ele present
            low = mid + 1;

        else
            high = mid - 1;
    }

    return low;
}

// ----------------------------------------
//    Brute Force   O(n)
// ----------------------------------------
int peakElement_Finder(int *arr, int len)
{
    int i = 0;
    while (arr[i] < arr[i + 1])
        i++;

    return i;
}

//   OR
//  return find(arr.begin(), arr.end(), *max_element(arr.begin(), arr.end())) - arr.begin();   <-----  using STL function

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {4, 6, 20, 16}, res = 0, size = sizeof(arr) / sizeof(arr[0]);
    res = peakElement_Finder(arr, size - 1);
    cout << "Peak Element of the Array : " << arr[res] << " at Index " << res << endl;

    return 0;
}

/*
EXPLANATION ::

        # PEAK ELEMENT  : an element which is MORE than its left and right side number ( More than 1 PEAK ele can be present )
        # Here we are applying Binary Search in an UNSORTED Array to find the peak element
        # If MID element is greater than both its neighbour on either side ?  if YES then return it.
           ELSE
        # Move accordingly to the side that is GREATER than the MID
*/