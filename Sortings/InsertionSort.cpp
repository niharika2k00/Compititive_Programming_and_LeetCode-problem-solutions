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

//  AIM : Try to make elements at the LEFT of the hole Minimum.
void InsertionSort(int *arr, int len)
{
    int hole, value, i;

    for (i = 1; i < len; i++)
    {
        hole = i;
        value = arr[i];

        while (hole > 0 && arr[hole - 1] > value) // Previous ele >  value
        {
            arr[hole] = arr[hole - 1]; // hole shift to Left by  1 idx
            hole--;
        }

        arr[hole] = value;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {7, 2, 4, 1, 5, 3};
    int len = sizeof(arr) / sizeof(arr[0]);

    InsertionSort(arr, len);

    for (auto ele : arr)
        cout << ele << "\t";

    return 0;
}