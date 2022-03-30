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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll coins = 0, ene = 0;
int main()
{
    ll m, n, i, j;
    cin >> m >> n;
    string s;
    vector<string> v(m);
    vector<vector<ll>> v1(m, vector<ll>(n, 0));

    for (i = 0; i < m; i++)
        cin >> v[i];

    for (i = 0; i < m; i++) //  row
    {
        for (j = 0; j < n; j++) //  column
        {
            if (i == 0)
            {
                if (v[i][j] == 'C')
                    coins++;
                v1[i][j] = m - i - 1;
            }
            else
            {
                if (v[i][j] == 'C')
                {
                    coins++;
                    ll a = m - i - 1;
                    v1[i][j] = min(v1[i - 1][j], -a);
                }
                else if (v[i][j] == 'H')
                {
                    if (v[i - 1][j] == 'H')
                        v1[i][j] = v1[i - 1][j];
                    else
                        v1[i][j] = m - i;
                }
                else if (v1[i - 1][j] < 0)
                    v1[i][j] = v1[i - 1][j];
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (v1[m - 1][i] < 0)
        {
            ll a = v1[m - 1][i];
            ene += -a;
        }
        else
            ene += v1[m - 1][i];
    }

    ene = 2 * ene;
    cout << coins << " " << ene;

    return 0;
}

void solve()
{
    int n, m, calories = 0;
    cin >> n >> m;
    vector<vector<char>> grid;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        vector<char> p = split_str(s);
        grid.pb(p);
    }

    for (int j = 0; j < m; j++) // column
    {
        int firstSpace = -1;
        int lastCoin = -1;

        for (int i = n - 1; i >= 0; i--)
        {
            if (grid[i][j] == 'C')
                lastCoin = i;
            if (grid[i][j] == '0' && firstSpace == -1)
                firstSpace = i;
        }

        if (lastCoin != -1)
            calories += 2 * (n - 1 - lastCoin);
        else
            calories += 2 * (n - 1 - firstSpace);
    }

    cout << totalCoins << " " << calories;
}