
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// -----------------------------
//  Using DFS  ✅✅
// -----------------------------
class Solution
{
public:
  // Function to detect cycle in an undirected graph.
  bool DFS(vector<int> adj[], vector<bool> &visited, int u, int parent)
  {
    visited[u] = true;

    // for(auto it = adj[u].begin(); it != adj[u].end(); it++) {...}
    for (auto &v : adj[u])
    {
      if (v == parent)
        continue;

      if (visited[v])
        return true;

      if (DFS(adj, visited, v, u))
        return true;
    }

    return false;
  }

  bool isCycle(int v, vector<int> adj[])
  {
    vector<bool> visited(v, false);

    for (int i = 0; i < v; i++)
      if (!visited[i] && DFS(adj, visited, i, -1)) // vertex not visited and encountered a cycle
        return true;

    return false;
  }
};

// -----------------------------
//  Using BFS
// -----------------------------
bool BFS(vector<int> adj[], vector<bool> &visited, int u)
{
  queue<pair<int, int>> que;

  que.push({u, -1});

  if (!visited[u])
    visited[u] = true;

  while (!que.empty())
  {
    pair<int, int> p = que.front();
    que.pop();
    int node = p.first;
    int parent = p.second;

    for (auto &v : adj[node])
    {
      if (!visited[v])
      {
        visited[v] = true;
        que.push({v, node});
      }
      else if (v != parent)
        return true;
    }
  }

  return false;
}
