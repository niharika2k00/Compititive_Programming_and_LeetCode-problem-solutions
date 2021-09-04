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

/* 

  # FLOOR & CEIL  ELEMENT ::
         when an element is just less than the given number means arr = { 2 3 5 8 } , key = 4 ............ then  ans = 3 (floor) ans ans = 5 (Ceil)
  
 */

// for finding the floor of the key that exsist in the array
int find_Floor(int arr[], int start, int end, int key)
{
    int mid, store = INT_MAX;

    // if (start <= end)
    while (end > start)
    {
        mid = (start + end) / 2;
        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid]) //  LEFT
            end = mid - 1;
        // return find_Floor(arr, start, mid - 1, key);

        // else if (arr[mid - 1] <= key && key < arr[mid])
        // return (mid - 1);

        else if (key > arr[mid])
        {
            // if (store > arr[mid])
            store = arr[mid];
            start = mid + 1;
            // return find_Floor(arr, mid + 1, end, key);
        }
    }

    {
        // If start and high cross each other
        //if (low > high)
        //	return -1;

        if (end >= start)
        {
            // If last element is smaller than x
            if (key >= arr[end])
                return end;

            mid = (start + end) / 2;

            if (arr[mid] == key)
                return mid;

            // If key lies between mid-1 and mid
            if (mid > 0 && arr[mid - 1] <= key && key < arr[mid])
                return mid - 1;

            if (key < arr[mid]) // LEFT
                return find_Floor(arr, start, mid - 1, key);

            // If mid-1 is not floor and key is greater than arr[mid],
            // key is more than arr[mid] means arr[mid] is one of the floor(LESS) value in comparison to key  RIGHT
            else
                return find_Floor(arr, mid + 1, end, key);
        }
        return -1;
    }

    int find_Ceil(int arr[], int start, int end, int key)
    {

        return 0;
    }

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int arr[] = {2, 4, 10, 16, 22, 30, 88}, key = 22, floorResult = 0, ceilResult = 0, size = sizeof(arr) / sizeof(arr[0]);

        floorResult = find_Floor(arr, 0, size - 1, key);
        ceilResult = find_Ceil(arr, 0, size - 1, key);

        cout << "asn : " << floorResult << endl;

        return 0;
    }