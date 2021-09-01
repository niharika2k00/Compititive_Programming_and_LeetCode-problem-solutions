/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.geeksforgeeks.org/find-first-and-last-positions-of-an-element-in-a-sorted-array/  
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

int FirstPosition(int arr[], int start, int end, int findNum)
{
    int mid = 0, ans = -1;
    while (end >= start)
    {
        mid = (start + end) / 2;
        if (findNum == arr[mid]) //  if num == mid , then compare with the previously exsisting elements inside the array to Find the FIRST POSITION.....
        {
            ans = mid;
            end = mid - 1;
        }
        else if (findNum < arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return ans;
}

int LastPosition(int arr[], int start, int end, int findNum)
{
    int mid = 0, ans = -1;
    while (end >= start)
    {
        mid = (start + end) / 2;
        if (findNum == arr[mid])
        {
            ans = mid;
            start = mid + 1;
        }
        else if (findNum < arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8};
    int i, n = sizeof(arr) / sizeof(arr[0]), findNum = 2, first = 0, last = 0;
    first = FirstPosition(arr, 0, n - 1, findNum); // n-1 as 0 ZERO indexing
    last = LastPosition(arr, 0, n - 1, findNum);

    cout << "\n First Occurence :  " << first << endl;
    cout << " Last Occurence :  " << last << endl;
    cout << "\n Total number of occurence of  " << findNum << " : " << (last - first + 1) << endl;

    return 0;
}