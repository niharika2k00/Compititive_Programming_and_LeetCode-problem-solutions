/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
    // Method - 1
    // USING RECURSION METHOD INVERTING THE EXSISTING TREE
    TreeNode *invertTree(TreeNode *root)
    {

        if (!root)
            return NULL;

        swap(root->right, root->left);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }

    // Method - 2
    // USING STACK DATA STRUCTURE METHOD INVERTING THE EXSISTING TREE
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return NULL;

        stack<*TreeNode> stack;
        stack.push(root);

        while (stack.size() > 0)
        {
            TreeNode *node = stack.top();
            stack.pop();

            swap(node->right, node->left);

            if (root->left)
                stack.push(root->left);

            if (root->right)
                stack.push(root->right);
        }

        return root;
    }
};
// @lc code=end
