/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
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

bool SubsetFinder(int arr[], int sum, int len)
{
    int consider, notConsider;
    if (len == 0 && sum == 0)
        return true;

    if (len == 0 && sum != 0)
        return false;

    // When Element is Greater than SUM
    if (arr[len - 1] > sum)
        return SubsetFinder(arr, sum, len - 1);

    consider = SubsetFinder(arr, sum - arr[len - 1], len - 1); //  Consider
    notConsider = SubsetFinder(arr, sum, len - 1);             // Not Consider

    return consider || notConsider;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {3, 34, 4, 12, 5, 2}, sum = 9, len = sizeof(arr) / sizeof(arr[0]);
    if (SubsetFinder(arr, sum, len))
        cout << "TRUE Subset is possible ";
    else
        cout << "FALSE Not posssible ";

    return 0;
}
