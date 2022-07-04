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

bool isValid(int i, int j, vector<vi> &graph)
{
    int n = graph.size();

    //  Out of bounds
    if (i < 0 or i >= n or j < 0 or j >= n)
        return false;

    if (graph[i][j] != 1)
        return false;

    return true;
}

int dfs(int i, int j, vector<vi> &graph)
{
    graph[i][j] = 2; // just any number so that we have a note that we have already visited the cell
    int cnt = 1;

    if (isValid(i + 1, j, graph)) //  Right
        cnt += dfs(i + 1, j, graph);

    if (isValid(i - 1, j, graph)) //  Left
        cnt += dfs(i - 1, j, graph);

    if (isValid(i, j + 1, graph)) //  Top
        cnt += dfs(i, j + 1, graph);

    if (isValid(i, j - 1, graph)) //  Down
        cnt += dfs(i, j - 1, graph);

    return cnt;
}

void addEdge(char c, int i, int j, vector<vi> &graph)
{
    if (c == 'C')
        graph[i][j] = 1;
    else
        graph[i][j] = 0;
}

void solve()
{
    int n;
    cin >> n;
    vector<vi> graph(n, vi(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            addEdge(c, i, j, graph);
        }
    }

    vi arr;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (graph[i][j] == 1) // Coins
                arr.pb(dfs(i, j, graph));
    }

    sort(all(arr), greater<int>());
    int a = 0, b = 0;

    for (int i = 0; i < (int)arr.size(); i++)
    {
        if (i % 2 == 0)
            a += arr[i];
        else
            b += arr[i];
    }

    cout << a << ' ' << b;
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
