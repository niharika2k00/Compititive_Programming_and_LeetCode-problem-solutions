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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {2, 5, 11, 4};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << accumulate(arr, arr + len, 0) << endl; // Sum

    /*
           ALGORITHM :

        Calculate total sum
        If Even , then divide into 2 means SUM / 2
                  else END ;
        EVEN : find the subarray that have SUM/2 value. (as done in SubsetSum.cpp file )
    */

    return 0;
}