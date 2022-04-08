
/*
________________________________________
  - By Niharika Dutta
 Code Link : https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
 Time Complexity :            O(n)
________________________________________
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

    int a[] = {5, -4, -2, 6, -1};
    int i, size = sizeof(a) / sizeof(a[0]), maxSum = 0, currentSum = 0;

    for (i = 0; i < size; i++)
    {
        currentSum += a[i];
        if (currentSum > maxSum)
            maxSum = currentSum;

        if (currentSum < 0) // negative sum
            currentSum = 0;
    }

    cout << "Maximum sum of the Longest Contiguous Subarray  :  " << maxSum << endl;
    return 0;
}