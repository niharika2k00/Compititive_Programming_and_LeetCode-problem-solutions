/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/
 Time Complexity :
________________________________________
----------------------------------------
 */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long
#define lli long long int
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

//  Sort an array consisting of 0s, 1s and 2s WITHOUT USING inbuild func. The functions should put all 0s first, then all 1s and all 2s in last.
//   Time Complexity :  O(n)
//   Space Complexity :  O(1)
//   Counting Sort || Dutch National FLag Algorithm

/*                     Intuition
                  -------------------
        If num = 0 ; swap with start [so that it occurs at the beginning of the array]
        If num = 2 ; swap with last
 */

void dutchNationalFlag(int *arr, int n)
{
    cout << "size = " << n << endl;
    int start = 0, end = n - 1, mid = 0;

    while (mid <= end)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[start]);
            start++;
            mid++;
        }

        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[end]);
            end--;
        }

        else if (arr[mid] == 1)
            mid = mid + 1;
    }
}

void printArray(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {0, 1, 2, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    dutchNationalFlag(arr, n);
    cout << "Array after performing Dutch National Flag Algorithm : ";
    printArray(arr, n);

    return 0;
}