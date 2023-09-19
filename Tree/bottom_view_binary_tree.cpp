
// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution
{
public:
  vector<int> bottomView(Node *root)
  {
    // Your code here
    map<int, int> mp;           // (line, node) sort acc to the line ...-1 0 1 2... left to right
    queue<pair<Node *, int>> q; // (node, line)
    vector<int> res;

    if (!root)
      return res;

    q.push({root, 0});

    while (!q.empty())
    {
      Node *rt = q.front().first;
      int line = q.front().second;

      q.pop();

      // Condition required for Top View BT
      // node added to map only once as it will be the top viewed node
      // if(mp.find(line) == mp.end())
      mp[line] = rt->data;

      if (rt->left)
        q.push({rt->left, line - 1});

      if (rt->right)
        q.push({rt->right, line + 1});
    }

    for (auto it : mp)
      res.push_back(it.second);

    return res;
  }
};