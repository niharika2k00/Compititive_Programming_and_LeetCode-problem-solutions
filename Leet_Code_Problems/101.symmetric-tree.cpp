/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */
// https://leetcode.com/problems/symmetric-tree/
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
    // Using Traversal Technique
    bool checkSymmetric(TreeNode *L, TreeNode *R)
    {
        if (!L && !R)
            return true;

        if (!L || !R) // anyone not there
            return false;

        if (L->val != R->val)
            return false;

        bool ans = checkSymmetric(L->left, R->right) && checkSymmetric(L->right, R->left); // when both are TRUE, return true.
        return ans;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;

        return checkSymmetric(root->left, root->right);
    }
};
// @lc code=end
