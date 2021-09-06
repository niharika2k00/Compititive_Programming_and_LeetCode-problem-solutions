/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :    
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

int peakElement_Finder(int arr[], int start, int size)
{
    int mid, end = size - 1;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (mid > 0 && mid < (size - 1))
        {
            if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1]) // arr[mid]  is the PEAK
                return arr[mid];
            else if (arr[mid - 1] > arr[mid]) // Move RIGHT Side as it is more promising. (EX : 10 20 30   , mid = 20)
                end = mid - 1;
            else
                start = mid + 1;
        }

        // Edge Case
        else if (mid == 0)
        {
            if (arr[0] > arr[1])
                return arr[0];
            else
                return arr[1];
        }

        else if (mid == (size - 1))
        {
            if (arr[size - 2] < arr[size - 1])
                return arr[size - 1];
            else
                return arr[size - 2];
        }
    }

    return 0;
}

/* 
EXPLANATION :: 

        # PEAK ELEMENT  : an element which is MORE than its left ans right side number ( More than 1 PEAK ele can be present )
        # Here we are applying Binary Search in an UNSORTED Array to find the peak element
        # If MID element is greater than both its neighbour on either side ?  if YES then return it.
           ELSE 
        # Move accordingly to the side that is GREATER than the MID    

*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {4, 6, 20, 16}, res = 0, size = sizeof(arr) / sizeof(arr[0]);
    res = peakElement_Finder(arr, 0, size);
    cout << "Peak Element of the Array : " << res << endl;

    return 0;
}