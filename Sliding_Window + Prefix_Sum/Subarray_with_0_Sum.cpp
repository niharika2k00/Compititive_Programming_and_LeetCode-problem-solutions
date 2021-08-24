
/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :    
 Time Complexity :  O(log n)    but unordered SET is O(1)
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {4, 2, -3, 1, 6};
    set<int> set;
    int i, currSum = 0, n = sizeof(arr) / sizeof(arr[0]);

    for (i = 0; i < n; i++)
    {
        currSum = currSum + arr[i];
        if (currSum == 0 || set.find(currSum) != set.end()) // if that currSum element is found in the SET.
            cout << "NOT POSSIBLE __ subarray with sum 0" << endl;

        set.insert(currSum);
    }

    cout << "Yeaaaaaaaaaaaaaaah Possible subarray with 0 Sum" << endl;

    return 0;
}