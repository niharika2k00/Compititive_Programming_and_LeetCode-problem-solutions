// Author: Bihan Chakraborty
// Linkedin: https://www.linkedin.com/in/bihan-chakraborty
// Github: https://github.com/Bihan001

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
const int MOD = 1e9 + 7;
const int INF = 1e18;
#define inputarr(arr, n)        \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];
#define printarr(arr, n)        \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << ' ';

void dfs(int u, int head, vector<vi> &graph, vi &groups, vector<bool> &visited)
{
    visited[u] = true;
    groups[u] = head;

    for (int v : graph[u])
    {
        if (!visited[v])
            dfs(v, head, graph, groups, visited);
    }
}

void solve()
{
    int n;
    cin >> n;
    vi arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int m;
    cin >> m;
    vector<vi> graph(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    vi groups(n);
    for (int i = 0; i < n; i++)
        groups[i] = i;

    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(i, i, graph, groups, visited);
    }

    unordered_map<int, int> groupamount;
    for (int i = 0; i < n; i++)
        groupamount[groups[i]] += arr[i];

    int maxval = 0;

    for (auto it : groupamount)
        maxval = max(maxval, it.second);

    cout << maxval;
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