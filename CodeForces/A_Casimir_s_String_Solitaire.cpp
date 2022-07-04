/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link : https://codeforces.com/contest/1579/problem/A   
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
        int a = 0, b = 0, c = 0, i = 0;
        string s;
        cin >> s;

        // We can cancel AB & BC
        for (i = 0; i < s.size(); i++)
        {
            if (s[i] == 'A')
                a++;
            else if (s[i] == 'B')
                b++;
            else
                c++;
        }

        int ans = a + c; // This is because for both A & C both needs a B to cancel out.
        if (ans == b)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}