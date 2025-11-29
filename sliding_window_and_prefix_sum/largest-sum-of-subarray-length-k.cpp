
/* 
________________________________________
----------------------------------------
 Author :  Niharika Dutta
 Code Link :   
 Time Complexity is O(n). 
________________________________________
----------------------------------------
 */

// SAME PROBLEM CAN BE DONE IN 2 WAYS ---> *  KANDANE ALGORITHM (done in array folder)
//                                         *  SLIDING WINDOW TECHNIQUE

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

    int i, n = 6, windowSumMax = 0, currSum = 0, k = 3;
    int arr[6] = {2, -1, 3, 5, 0, 1};

    if (n < k)
        cout << "Not Possible" << endl;

    for (i = 0; i < k; i++)
        currSum = currSum + arr[i];

    windowSumMax = currSum;

    for (i = k; i < n; i++)
    {
        currSum = currSum + arr[i] - arr[i - k];
        windowSumMax = max(currSum, windowSumMax);
    }

    cout << "Largest sum of the subarray with Window Size k : " << windowSumMax << endl;

    return 0;
}