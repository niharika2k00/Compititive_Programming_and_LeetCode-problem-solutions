/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :
 Time Complexity :   O(log n)
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

int Binary_Search(int arr[], int start, int end, int findNum)
{
    int mid = 0;
    while (end >= start)
    {
        mid = (start + end) / 2;
        if (findNum == arr[mid])
            return mid;
        else if (findNum < arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[10] = {4, 8, 10, 16, 22, 28, 40, 56, 69, 100};
    int i, n = 10, findNum = 69, ans = 0;
    ans = Binary_Search(arr, 0, n - 1, findNum); // n-1 as 0 ZERO indexing

    cout << " Yes , it is Present in the Array at index " << ans << endl;

    return 0;
}

/*

STL :  BUILD IN FUNCTION

  # For Binary Search --->  ARAAY MUST BE SORTED

binary_search(startaddress, endaddress, valuetofind)
e.g.  binary_search(arr, arr + 10 , 8);

*/