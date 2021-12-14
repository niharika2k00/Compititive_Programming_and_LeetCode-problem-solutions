
/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codechef.com/problems/CHEFRES
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

    /*
            [L , R)  =>  inclusive L and exclusive R
            Lower_bound ( )  =>  Index of the next smallest number just GREATER than or EQUAL to that number.
    */

    test
    {
        int n, m, i, l, r, arrivalTime;
        cin >> n >> m;
        vector<pair<int, int>> timing;
        for (i = 0; i < n; i++)
        {
            cin >> l >> r;
            timing.push_back(make_pair(l, r)); //  timing.push_back({3 , 5}))
        }

        // Logical Part
        sort(timing.begin(), timing.end());

        for (i = 0; i < m; i++)
        {
            cin >> arrivalTime;
            auto it = lower_bound(timing.begin(), timing.end(), make_pair(arrivalTime, INT_MIN));
            cout << "val = " << it->first << " , ";

            if (it == timing.begin())
                cout << (timing.front().first - arrivalTime) << endl;

            else if (it == timing.end())
            {
                if (timing.back().second > arrivalTime)
                    cout << "0\n";
                else
                    cout << "-1\n";
            }

            else
            {
                auto prevOpening = it - 1;
                if (prevOpening->second > arrivalTime) // means its within the bound
                    cout << "0\n";
                else
                    cout << (it->first - arrivalTime) << endl;
            }
        }
    }

    return 0;
}