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

int helper(int intern, int pw, vector<vector<int>> &store)
{
    //  Initialize Day1
    for (int i = 1; i <= intern; i++)
    {
        store[0][i] = 5000 * (i);
        if (pw == 5000 * (i))
            return i;
    }

    for (int i = 1; i < 50; i++) // days
    {
        for (int j = 1; j <= intern; j++) // intern
        {
            int val = store[i - 1][j] + 5000 + i;
            store[i][j] = val;
            if (pw == val)
                return j;
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int intern = 10, pw = 25003;
    vector<vector<int>> store(50, vector<int>(intern, 0));

    int res = helper(intern, pw, store);
    cout << "Intern : " << res << endl;

    return 0;
}
