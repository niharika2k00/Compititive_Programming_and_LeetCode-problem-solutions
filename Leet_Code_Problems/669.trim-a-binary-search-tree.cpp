/*
 * @lc app=leetcode id=669 lang=cpp
 *
 * [669] Trim a Binary Search Tree
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
 * https://leetcode.com/problems/trim-a-binary-search-tree/
 *
 */
class Solution
{
public:
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (!root)
            return nullptr;

        if (root->val < low) //  Only RIGHT SUBTREE return  NO NEED to see the left side as it will be More LESS.
            return trimBST(root->right, low, high);

        if (root->val > high) // No chance to visit RIGHT SUBTREE, means return ONLY LEFT SUBTREE.
            return trimBST(root->left, low, high);

        if (root->val >= low && root->val <= high)
        {
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        }

        return root;
    }
};
// @lc code=end
