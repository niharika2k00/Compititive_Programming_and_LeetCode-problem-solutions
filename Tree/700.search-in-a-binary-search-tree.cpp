/*
 * @lc app=leetcode id=700 lang=cpp
 *
 * [700] Search in a Binary Search Tree
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
 * https://leetcode.com/problems/search-in-a-binary-search-tree/
 *
 */
class Solution
{
public:
    // Find ROOT NODE with value equals VAL and Return the subtree rooted with that node.
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (!root)
            return NULL;

        if (root->val == val)
            return root;

        if (root && root->val > val)           //  val is LESS than root
            return searchBST(root->left, val); // return Left Subtree

        return searchBST(root->right, val);
    }
};

// @lc code=end
