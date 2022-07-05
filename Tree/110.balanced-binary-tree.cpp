/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
 * https://leetcode.com/problems/balanced-binary-tree/
 *
 */
class Solution
{
    //  Check Balanced Binary Tree
    //  Check whether A BINARY TREE in which the Left & Right Subtrees of every node differ in height by NO more than 1.
public:
    //  Code of Height of the Binary Tree
    int helper(TreeNode *root)
    {
        int leftHt = 0, rightHt = 0;

        if (!root)
            return 0;

        leftHt = helper(root->left);
        rightHt = helper(root->right);

        if (abs(leftHt - rightHt) > 1)
            return -1;

        if (leftHt == -1 || rightHt == -1)
            return -1;

        return max(leftHt, rightHt) + 1;
    }

    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;

        int res = helper(root);
        return (res == -1) ? false : true;
    }
};
// @lc code=end
