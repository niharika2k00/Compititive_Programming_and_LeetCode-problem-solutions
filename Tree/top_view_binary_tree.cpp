/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

class Solution
{
public:
  // Function to return a list of nodes visible from the top view
  // from left to right in Binary Tree.
  vector<int> topView(Node *root)
  {
    // Your code here
    map<int, int> mp;           // (line, node) sort acc to the line ...-1 0 1 2...
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

      // node added to map only once as it will be the top viewed node
      if (mp.find(line) == mp.end())
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