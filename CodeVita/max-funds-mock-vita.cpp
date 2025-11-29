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

class Graph
{
public:
    int v;
    int index;
    vector<vector<int>> adjacency_list;

    Graph(int node)
    {
        index = 0;
        adjacency_list.resize(node + 1);
    }

    void set_edge(int start, int end)
    {
        adjacency_list[start].push_back(end);
        adjacency_list[end].push_back(start);
        cout << "\n"
             << start << " --> " << end << " ";
    }

    void dfsUtil(int start, vector<bool> &visited, int &sum, vector<int> &vec)
    {
        visited[start] = true;
        sum = sum + vec[start];
        cout << "sum = " << sum << endl;

        for (auto i = adjacency_list[start].begin(); i != adjacency_list[start].end(); ++i)
        {
            if (!visited[*i])
            {
                // sum = sum + vec[*i - 1];
                dfsUtil(*i, visited, sum, vec);
            }
        }
    }

    void DFS(vector<int> &vec)
    {
        vector<bool> visited(adjacency_list.size() + 1, false);
        int maxFund = INT_MIN, sum = 0;

        for (int i = 0; i < adjacency_list.size(); i++)
        {
            if (!visited[i])
            {
                sum = 0;
                dfsUtil(i, visited, sum, vec);

                if (sum > maxFund)
                    maxFund = sum;
            }
        }

        cout << "\n"
             << maxFund << endl;
    }
};

void solve()
{
    int n, i, pair;
    cin >> n;
    vector<int> vec(n);
    for (i = 0; i < n; i++)
        cin >> vec[i];
    cin >> pair;

    Graph g(n);

    //  graph construction
    while (pair--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g.set_edge(a, b);
    }

    g.DFS(vec);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}