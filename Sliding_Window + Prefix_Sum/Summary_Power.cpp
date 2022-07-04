/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codechef.com/problems/SUMPOWER  
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    test
    {
        int i, power = 0, n, k, result = 0, diff[n - 1]; // array size doesn't start with 0
        cin >> n >> k;
        string s;
        cin >> s;

        // Diff[] array ready
        for (i = 0; i < n - 1; i++)
        {
            if (s[i] != s[i + 1])
                diff[i] = 1;
            else
                diff[i] = 0;
        }

        // Sum till K (Window size)
        for (int i = 0; i < k; i++)
            power = power + diff[i];

        result = result + power;

        for (int i = k; i < n - 1; i++)
        {
            power = power + diff[i] - diff[i - k];
            result = result + power;
        }

        cout << result << endl;
    }

    return 0;
}

/* 

LOGIC :: 

   -  Window size K length 
   -  Note the differene in a separate array diff[]
   - [LOOP] First store K length window  ( done in sliding window problem )  from  0   to   <k
   - [LOOP] shift the window of size K , and store its sum.(Here Power)

 */