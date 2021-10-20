
/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://atcoder.jp/contests/abc223/tasks/abc223_d  
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

    // TOPOLOGICAL SORT IN GRAPHS --- kahns algorithm (bfs)
    int n, m, i;
    cin >> n >> m;

    vector<vector<int>> adjacency_list(n);
    vector<int> inDegree(n, 0);
    priority_queue<int, vector<int>, greater<int>> queue; // Min heap as its asked for sorted array
    vector<int> result(n);

    for (i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adjacency_list[a].push_back(b);
        inDegree[b]++;
    }

    for (i = 1; i <= n; i++)
        if (inDegree[i] == 0)
            queue.push(i);

    while (!queue.empty())
    {
        int frontEle;
        frontEle = queue.top();
        queue.pop();
        result.push_back(frontEle);

        for (auto it : adjacency_list[frontEle]) // traverse the row of the frontEle in the 2D array
        {
            inDegree[it]--;
            if (inDegree[it] == 0)
                queue.push(it);
        }
    }

    if (result.size() != n) // acyclic
        cout << "-1\n";
    else
    {
        for (i = 0; i < n; i++)
            cout << result[i] << " ";
        cout << endl;
    }

    return 0;
}