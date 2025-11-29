/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.geeksforgeeks.org/find-element-bitonic-array/
 Time Complexity :    O(log n)
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

int findBitonicPoint(int arr[], int start, int end)
{
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;
        else if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1]) //  EX : 10  50  80 ,  mid = 50 ..........  RIGHT SIDE move
            start = mid + 1;
        else if (arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1]) //  LEFT
            end = mid - 1;
    }
    return -1;
}

int ascendingPartBS(int arr[], int start, int end, int key)
{
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int descendingPartBS(int arr[], int start, int end, int key)
{
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int findValue(int arr[], int start, int end, int key, int bitonicPt)
{
    if (key == arr[bitonicPt])
        return bitonicPt; //  returning the INDEX
    else if (key > arr[bitonicPt])
        return -1;
    else
    {
        int upward = ascendingPartBS(arr, start, bitonicPt - 1, key); // Finding key in the Left part
        if (upward != -1)
            return upward;
        else
        {
            int downward = descendingPartBS(arr, bitonicPt + 1, end, key);
            return downward;
        }
    }
    return 0;
}

/*
EXPLAINATIONS ::
        BITONIC ARRAY ---> array where we can apply binary search though it is not sorted
                           Structure like a hill.
                           First the values increases then reaches a PEAK and after that it decreases.

         * Find a Key Element in Bitonic Array  :
                                       - STEP 1 :  First Search in the first part(i.e before the PEAK element)
                                       - STEP 2 :  if KEY not found in step 1 then search in the Right (downward) part of the array

 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {-8, 1, 2, 3, 40, 5, -2, -3}, bitonicPt = 0, find_key = 0, key = 1, size = sizeof(arr) / sizeof(arr[0]);

    bitonicPt = findBitonicPoint(arr, 0, size - 1);
    cout << "Bitonic Point  : " << arr[bitonicPt] << " at Index " << bitonicPt << endl;

    find_key = findValue(arr, 0, size - 1, key, bitonicPt);
    if (find_key == -1)
        cout << "Key is Not Found" << endl;
    else
        cout << "Key is Found at Index " << find_key << endl;

    return 0;
}