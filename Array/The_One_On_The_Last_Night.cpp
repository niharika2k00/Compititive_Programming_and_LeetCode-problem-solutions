/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codechef.com/FOUR21C/problems/S06E06
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
         METHOD - I      First SORT the array then , INCREMENT arr[0] = arr[0] +  1      K times.

         METHOD - II     We can take another Vector / Multiset and do the same but it will increase the time complexity.
     */
    test
    {
        string s;
        cin >> s;
        ll k, i, product = 1;
        cin >> k;

        sort(s.begin(), s.end());

        while (k--) //  when digit NOT 9
        {
            if (s[0] == '9')
                continue;
            s[0] = s[0] + 1;
            sort(s.begin(), s.end());
        }

        for (i = 0; i < s.size(); i++)
            product = product * (s[i] - '0'); // ASCII character '0' is 48.

        cout << product << endl;
    }

    return 0;
}