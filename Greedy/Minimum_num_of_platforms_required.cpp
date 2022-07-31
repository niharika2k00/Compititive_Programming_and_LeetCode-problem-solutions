/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://takeuforward.org/data-structure/minimum-number-of-platforms-required-for-a-railway/
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

    int arrival[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(arrival) / sizeof(arrival[0]), i = 1, j = 0, result = 1, platformUsed = 1;

    sort(arrival, arrival + n);
    sort(dep, dep + n);

    //  2 Pointer where i iterates over arrival[] and j iterates over dep[]
    while (i < n && j < n)
    {
        if (arrival[i] <= dep[j]) //  if arrival[i] train is coming before than the departure train.
        {
            platformUsed++;
            i++;
        }
        else
        {
            platformUsed--;
            j++;
        }

        result = max(result, platformUsed);
    }

    cout << "Minimum Platforms needed will be " << result << endl;

    return 0;
}