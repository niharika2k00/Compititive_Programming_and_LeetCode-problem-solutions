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
Nearly Sorted Array :: 

- Nor Fully sorted .
- the ith element can be in (i + 1 )th position , i th position or (i - 1)th position.

 */

int searchNearlySortedArray(int arr[], int start, int end, int findNum)
{
    int mid = (start + end) / 2;
    if (end >= start)
    {
        if (findNum == arr[mid])
            return mid;

        else if (start <= mid - 1 && arr[mid - 1] == findNum)
            return mid - 1;

        else if (mid + 1 <= end && arr[mid + 1] == findNum)
            return mid + 1;

        else if (findNum < arr[mid])
            return searchNearlySortedArray(arr, start, mid - 2, findNum);

        else if (findNum > arr[mid])
            return searchNearlySortedArray(arr, mid + 2, end, findNum);
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {42, 55, 6, 10, 16}, findNum = 42, res = 0, size = sizeof(arr) / sizeof(arr[0]);
    res = searchNearlySortedArray(arr, 0, size - 1, findNum);
    cout << res << endl;
    return 0;
}