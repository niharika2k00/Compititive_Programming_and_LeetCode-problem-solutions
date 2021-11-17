
/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.geeksforgeeks.org/equilibrium-index-of-an-array/
 Time Complexity :   O (n)
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

int getEquilibrium(int arr[], int n)
{
    int i, sum = 0, leftSum = 0;
    sum = accumulate(arr, arr + n, sum); //  sum of the array    accumulate( start , end , initialValue)

    for (i = 0; i < n; i++)
    {
        sum = sum - arr[i];
        if (sum == leftSum)
            return i;
        leftSum = leftSum + arr[i];
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {-7, 1, 5, 2, -4, 3, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "First Point of equilibrium is at index " << getEquilibrium(arr, n) << "\n";
    return 0;
}