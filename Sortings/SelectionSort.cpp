/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :
 Time Complexity :   O(n^2)
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

void SelectionSort(int *arr, int len)
{
    int minIdx = 0;

    for (int i = 0; i < len; i++)
    {
        minIdx = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[minIdx] > arr[j])
                minIdx = j; //  Stores the MINIMUM index
        }

        swap(arr[minIdx], arr[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {7, 2, 4, 1, 5, 3};
    int len = sizeof(arr) / sizeof(arr[0]);

    SelectionSort(arr, len);

    for (auto ele : arr)
        cout << ele << "\t";

    return 0;
}