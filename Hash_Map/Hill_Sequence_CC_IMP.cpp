/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codechef.com/NOV21C/problems/HILLSEQ
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

    test
    {
        ll n, i, x, flag = 0;
        cin >> n;
        vector<ll> result;
        map<ll, ll> mp; //  first =  num    ,  second = count/freq

        for (i = 0; i < n; i++)
        {
            cin >> x;
            mp[x]++; //  frequency count
        }

        for (auto it : mp)
        {
            if (it.second >= 3)
            {
                flag = 1;
                break;
            }
            result.push_back(it.first);
        }

        sort(result.begin(), result.end());
        int len = result.size();

        if (flag == 1 || mp[result[len - 1]] == 2)
            cout << "-1";
        else
        {
            for (ll i = 0; i < len; i++)
                if (mp[result[i]] == 2) // elements with 2 frequency
                    cout << result[i] << " ";

            for (ll i = len - 1; i >= 0; i--)
                cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
