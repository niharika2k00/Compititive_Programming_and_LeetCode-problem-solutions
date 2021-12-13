/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codechef.com/DEC21C/problems/VANDH
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
        int i, hill, valley, minimum = 0, zero = 0, one = 0;
        cin >> hill >> valley;
        string str;

        if (hill == valley)
        {
            for (i = 0; i < hill + 1; i++) //  hill+1 times append into string
                str = str + "01";
        }

        else if (hill > valley)
        {
            minimum = min(hill, valley);
            while (minimum--) // basically for Valley
                str = str + "01";

            int diff = hill - valley;
            for (i = 0; i < diff; i++)
                str = str + "010";
        }

        else if (valley > hill)
        {
            minimum = min(hill, valley);
            while (minimum--)
                str = str + "10";

            int diff = valley - hill;
            for (i = 0; i < diff; i++)
                str = str + "101";
        }

        int len = str.length();
        cout << len << endl;
        for (i = 0; i < len; i++)
            cout << str[i];

        cout << endl;
    }

    return 0;
}