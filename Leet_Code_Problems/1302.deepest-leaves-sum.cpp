/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
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
 */
class Solution
{
public:
    int Height(TreeNode *root) // Depth of the tree
    {
        int leftHt = 0, rightHt = 0;
        if (root == NULL)
            return 0;

        // Find the height of left, right subtrees
        leftHt = Height(root->left);
        rightHt = Height(root->right);
        return (max(leftHt, rightHt) + 1);
    }

    int sum = 0;
    void LeavesSum(TreeNode *root, int height, int deep)
    {
        if (root->left == NULL && root->left == NULL && deep == height)
        {
            sum = sum + root->val;
            return;
        }

        if (root->left)
            LeavesSum(root->left, height, deep + 1);

        if (root->right)
            LeavesSum(root->right, height, deep + 1);
    }

    int deepestLeavesSum(TreeNode *root)
    {
        if (!root)
            return 0;

        int height = 0;
        height = Height(root);
        LeavesSum(root, height, 1);
        cout << height << endl;
        return sum;
    }
};
// @lc code=end
