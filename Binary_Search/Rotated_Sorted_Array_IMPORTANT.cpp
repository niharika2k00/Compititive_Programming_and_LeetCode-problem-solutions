/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :    
 Time Complexity :   O (logn) ---- using Binary Search 
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

/* 
           Logic is to Find the MINUMUM element in the array.

           - Bcz we know that the array in Binary_Search is always SORTED
           - So, we can use LINEAR SEARCH (to find the min ele)   --------->   Time Complexity : O (n) 
           - Using Binary_Search                                  --------->   Time Complexity : O (log n) 
    
*/

int minimumNumberOfRotation(int arr[], int start, int end)
{
    int mid = (start + end) / 2, next, prev;
    cout << "MID = " << mid << endl;

    // when already Sorted
    if (end < start)
        return 0;

    // if the minimum element lies in the MID
    if (arr[mid - 1] > arr[mid] && arr[mid] < arr[mid + 1] && start < mid)
        return mid;

    // when (mid + 1) element is MIN
    if (arr[mid] > arr[mid + 1] && mid < end)
        return (mid + 1);

    // if min on Right part  --- means left side Sorted
    if (arr[start] < arr[mid])
        return minimumNumberOfRotation(arr, mid + 1, end);

    // if min on Left part  --- means right side Sorted
    if (arr[mid] < arr[end])
        return minimumNumberOfRotation(arr, start, mid - 1);

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {15, 20, 100, 5, 8};
    int n = sizeof(arr) / sizeof(arr[0]), result = 0;
    result = minimumNumberOfRotation(arr, 0, n - 1); // n-1 as 0 ZERO indexing

    if (!result)
        cout << "NO ROTATION NEEDED .... YEAhhhhh .. ";
    else
        cout << "\n Array rotated  " << result << " Times \n";
    return 0;
}