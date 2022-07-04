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
        if (root1 == NULL && root2 == NULL)
            return NULL;
        if (root1 == NULL && root2)
            return root2;
        if (root2 == NULL && root1)
            return root1;

        TreeNode *resultant = new TreeNode(root1->val + root2->val);
        resultant->left = mergeTrees(root1->left, root2->left);
        resultant->right = mergeTrees(root1->right, root2->right);

        return resultant;
    }
};
// @lc code=end
