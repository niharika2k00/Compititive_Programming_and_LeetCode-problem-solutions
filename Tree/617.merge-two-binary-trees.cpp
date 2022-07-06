/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
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
 * https://leetcode.com/problems/merge-two-binary-trees/
 *
 */
class Solution
{
public:
    // TreeNode *resultant;

    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return NULL;

        if (!root1)
            return root2;

        if (!root2)
            return root1;

        TreeNode *resultant = new TreeNode(root1->val + root2->val);
        resultant->left = mergeTrees(root1->left, root2->left);
        resultant->right = mergeTrees(root1->right, root2->right);

        return resultant;

        // ------------------------------------
        // Time Complexity :   O(n)
        //  Space Complexity :  O(1)
        // ------------------------------------
        if (!root1 && !root2)
            return NULL;

        if (!root1)
            return root2;

        if (!root2)
            return root1;

        root1->val = root1->val + root2->val;

        // Left DFS traversal
        if (root1->left || root2->left)
            root1->left = mergeTrees(root1->left, root2->left);

        // Right DFS traversal
        if (root1->right || root2->right)
            root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};
// @lc code=end
