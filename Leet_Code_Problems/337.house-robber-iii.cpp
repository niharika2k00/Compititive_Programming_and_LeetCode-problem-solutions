/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    unordered_map<TreeNode *, int> hashMap;
    int rob(TreeNode *root)
    {
        if (!root)
            return 0;
        if (hashMap.count(root))
            return hashMap[root];

        int total = 0;
        if (root->left)
            total = total + rob(root->left->left) + rob(root->left->right);
        if (root->right)
            total = total + rob(root->right->left) + rob(root->right->right);

        hashMap[root] = max(root->val + total, rob(root->left) + rob(root->right));
        return hashMap[root];
    }
};
// @lc code=end
