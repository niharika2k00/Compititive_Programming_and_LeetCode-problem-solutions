/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
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
 * Two nodes of a binary tree are COUSINS if they have the same depth with different parents.
 *
 */
class Solution
{
public:
    int depthFinder(TreeNode *root, int x)
    {
        depthFinder(root, x);
    }

    bool isCousins(TreeNode *root, int x, int y)
    {
        if (root == NULL)
            return false;

        int depthX = depthFinder(root, x);
    }
};
// @lc code=end
