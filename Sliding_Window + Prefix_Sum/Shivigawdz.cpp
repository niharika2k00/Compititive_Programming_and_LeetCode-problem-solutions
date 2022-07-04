/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :   https://www.codechef.com/problems/SHIVIGOD 
 Time Complexity :  
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

// Find the MAXIMUM  average of the numbers of any contiguous subarray of length between A and B, inclusive.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    test
    {
        int n, b, a, i, j;
        cin >> n >> b >> a;
        vector<int> vec(n);
        for (i = 0; i < n; i++)
            cin >> vec[i];

        for (i = 0; i < n; i++)
    }

    // have not understood
    // SOLUTION LINKS
    // https://www.codechef.com/viewsolution/49830685
    // https://www.codechef.com/viewsolution/49013843

    return 0;
}