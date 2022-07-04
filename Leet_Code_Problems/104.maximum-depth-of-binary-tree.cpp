/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
    int maxDepth(TreeNode *root)
    {
        int rightSubTree = 0, leftSubTree = 0;
        if (root == NULL)
            return 0;
        else
        {
            if (root->right)
                rightSubTree = maxDepth(root->right);
            if (root->left)
                leftSubTree = maxDepth(root->left);
        }
        return (max(rightSubTree, leftSubTree) + 1);
    }
};
// @lc code=end
