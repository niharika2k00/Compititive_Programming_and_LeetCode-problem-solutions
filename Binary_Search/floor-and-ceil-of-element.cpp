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
    while (end >= start)
    {
        mid = (start + end) / 2;
        if (arr[mid] == key)
            return arr[mid];

        else if (key < arr[mid]) //  LEFT
            end = mid - 1;

        else if (key > arr[mid]) // RIGHT --- means when the key is large than the mid then Store the MID in a variable for finding the nearest FLOOR Value.
        {
            // if (store > arr[mid])
            store = arr[mid];
            start = mid + 1;
        }
    }
    return store;
}

// Ceil Value finder (Lower than the key)
int find_Ceil(int arr[], int start, int end, int key)
{
    int mid, store = INT_MIN;
    while (end >= start)
    {
        mid = (start + end) / 2;
        if (arr[mid] == key)
            return arr[mid];

        else if (key < arr[mid]) //  LEFT
        {
            store = arr[mid];
            end = mid - 1;
        }

        else if (key > arr[mid]) // RIGHT --- means when the key is large than the mid then Store the MID in a variable for finding the nearest FLOOR Value.
            start = mid + 1;
    }
    return store;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {2, 4, 10, 16, 22, 30, 88}, key = 28, floorResult = 0, ceilResult = 0, size = sizeof(arr) / sizeof(arr[0]);

    floorResult = find_Floor(arr, 0, size - 1, key);
    ceilResult = find_Ceil(arr, 0, size - 1, key);

    cout << "Floor Value  : " << floorResult << "\tCeil Value  : " << ceilResult << endl;

    return 0;
}