
/* 
________________________________________
----------------------------------------
 Author :  Niharika Dutta
 Code Link :    
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

    // Print the first negative number of every window of K size .

    int arr[] = {-2, -8, 3, 4, 10, -6, 5, -1};
    vector<int> vecAnswer;
    vector<int> storeNeg;
    int n = 8, k = 3, count = 0, i;

    for (i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            storeNeg.push_back(arr[i]);
            break;
        }
    }

    for (i = k; i < n; i++)
    {
        if (arr[i - k] < 0)
    }

    return 0;
}