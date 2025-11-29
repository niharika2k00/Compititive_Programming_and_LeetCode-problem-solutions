

// ----------------------------------------------------------------
// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long int
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
const int MOD = 1e9 + 7;
const ll INF = 1e18;
#define inputarr(arr, n)       \
    for (ll i = 0; i < n; i++) \
        cin >> arr[i];
#define printarr(arr, n)       \
    for (ll i = 0; i < n; i++) \
        cout << arr[i] << ' ';

int totalCoins = 0;

vector<char> split_str(string s)
{
    vector<char> ans;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == 'C')
            totalCoins++;
        ans.pb(s[i]);
    }
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        vector<char> p = split_str(s);
        grid.pb(p);
    }
    int calories = 0;
    for (int j = 0; j < m; j++)
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
        {
            calories += 2 * (n - 1 - lastCoin);
        }
        else
        {
            calories += 2 * (n - 1 - firstSpace);
        }
    }
    cout << totalCoins << " " << calories;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}