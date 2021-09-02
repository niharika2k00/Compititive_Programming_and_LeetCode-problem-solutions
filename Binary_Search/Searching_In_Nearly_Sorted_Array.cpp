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

int searchNearlySortedArray(int arr[], int start, int end, int findNum)
{
    int mid = (start + end) / 2;
    if (end >= start)
    {
        if (findNum == arr[mid])
            return mid;

        if (start <= mid - 1 && arr[mid - 1] == findNum)
            return mid - 1;

        if (mid + 1 <= end && arr[mid + 1] == findNum)
            return mid + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {42, 5, 8, 10, 16}, findNum = 10, res = 0, size = sizeof(arr) / sizeof(arr[0]);
    res = searchNearlySortedArray(arr, 0, size - 1, findNum);

    return 0;
}