/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
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
 *
 * https://leetcode.com/problems/insert-into-a-binary-search-tree/
 *
 */
class Solution
{
public:
    TreeNode *BinarySearch(TreeNode *root, TreeNode *NewNode, int val)
    {
        if (root == NULL)
            return NewNode;

        if (val > root->val)
            root->right = BinarySearch(root->right, NewNode, val);

        if (val < root->val)
            root->left = BinarySearch(root->left, NewNode, val);

        return root;
    }

    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *NewNode = new TreeNode(val); //  Node Create
        NewNode->left = NewNode->right = NULL;

        return BinarySearch(root, NewNode, val);
    }
};
// @lc code=end
