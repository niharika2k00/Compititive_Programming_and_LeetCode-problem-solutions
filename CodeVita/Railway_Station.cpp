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

//    Find the MINIMUM number of platforms needed.
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int len = 2, platform, i = 0, j, ans;
    vector<int> arrivalTime{2, 4};
    vector<int> stoppingTime{6, 2};

    //  Departure Time
    for (i = 0; i < len; i++)
    {
        stoppingTime[i] = arrivalTime[i] + stoppingTime[i];
        // cout << stoppingTime[i] << "\t";
    }

    //  Sort both the array
    sort(arrivalTime.begin(), arrivalTime.end());
    sort(stoppingTime.begin(), stoppingTime.end());

    // ---------------------------------------
    //       TWO POINTERS
    // ---------------------------------------
    platform = 1, i = 1, j = 0, ans = 1;
    while (i < len && j < len)
    {
        if (arrivalTime[i] <= stoppingTime[j]) //  NO platform empty, still occupied by other.
        {
            platform++;
            i++;
        }
        else if (arrivalTime[i] > stoppingTime[j])
        {
            platform--;
            j++;
        }

        ans = max(ans, platform);
    }

    cout << ans << endl;

    return 0;
}