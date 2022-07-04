/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
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
 * https://leetcode.com/problems/range-sum-of-bst/
 *
 */
class Solution
{
public:
    int sum = 0;

    int rangeSumBST(TreeNode *root, int low, int high) /* PREORDER Traversal */
    {
        if (root == NULL)
            return 0;

        if (root->val >= low && root->val <= high)
            sum = sum + root->val;

        if (root->left)
            rangeSumBST(root->left, low, high);

        if (root->right)
            rangeSumBST(root->right, low, high);

        return sum;
    }
};
// @lc code=end
