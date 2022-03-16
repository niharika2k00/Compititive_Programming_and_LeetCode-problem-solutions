/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link : https://www.codingninjas.com/codestudio/contests/codestudio-weekend-contest-11/problems/17377
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
/*
        Sum of the 2 element to form a pair. Then from all the possible pairs return the K th GREATEST element(answer).
*/

int countGreaterThanMid(int mid, vector<int> &arr, int len)
{
    int count = 0, i = 0, j = len - 1;

    //   for every i-th element
    for (i = 0; i < len; i++)
    {
        while (i < j && arr[i] + arr[j] < mid)
            j--; // decrement the upper limit

        if (j > i)
            count = count + (j - i);
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, len, high, low, ans = 0, mid = 0, k = 2;
    vector<int> arr{4, 3, 2, 7, 8};
    len = arr.size();

    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());

    low = arr[len - 1] + arr[len - 2];
    high = arr[0] + arr[1];
    ans = low;

    while (high >= low)
    {
        mid = (high + low) / 2;
        if (countGreaterThanMid(mid, arr, len) >= k)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    cout << "Answer : " << ans << endl;

    return 0;
}