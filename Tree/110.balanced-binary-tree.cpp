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
    // A BINARY TREE in which the Left & Right Subtrees of every node differ in height by NO more than 1.
public:
    int Checking(TreeNode *root)
    {
        int left, right, diff;
        if (!root)
            return 0;

        left = Checking(root->left);
        if (left == -1)
            return -1;
        right = Checking(root->right);
        if (right == -1)
            return -1;

        diff = abs(left - right);
        if (diff > 1)
            return -1;
        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;

        auto result = Checking(root);
        if (result == -1)
            return false;
        return true;
    }
};
// @lc code=end
