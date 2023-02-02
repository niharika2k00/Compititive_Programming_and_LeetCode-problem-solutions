
// https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// ---------------------------
//        Using DFS
// ---------------------------

Class Solution
{
public:
  bool bipartiteDFS(int curr, vector<int> adj[], vector<int> &color, int currColor)
  {
    color[curr] = currColor;

    for (auto &it : adj[curr])
    {
      if (color[it] == currColor) // same color adj node
        return false;

      if (color[it] == -1) // never colored
      {
        int colorOfV = !currColor;

        if (bipartiteDFS(it, adj, color, colorOfV) == false)
          return false;
      }
    }

    return true;
  }

  // ---------------------------
  //        Using BFS
  // ---------------------------
  bool bipartiteBFS(int curr, vector<int> adj[], vector<int> &color, int currColor)
  {
    queue<int> que;

    if (color[curr] == -1)
      color[curr] = currColor;

    que.push(curr);

    while (!que.empty())
    {
      int u = que.front();
      que.pop();

      for (auto &it : adj[u])
      {
        if (color[it] == color[u])
          return false;

        if (color[it] == -1)
        {
          color[it] = !color[u];

          que.push(it);
        }
      }
    }

    return true;
  }

  // Main Func
  bool isBipartite(int V, vector<int> adj[])
  {
    vector<int> color(V, -1); // no one coloured as of now

    for (int i = 0; i < V; i++)
    {
      if (color[i] == -1)
        if (bipartiteDFS(i, adj, color, 1) == false)
          return false;
    }

    return true;
  }
}
