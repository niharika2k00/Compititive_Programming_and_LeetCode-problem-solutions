/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 *
 */
class Solution
{
public:
    void Inorder_Traversal(TreeNode *root, vector<int> &inorderArr)
    {
        if (root->left)
            Inorder_Traversal(root->left, inorderArr);
        inorderArr.push_back(root->val);
        if (root->right)
            Inorder_Traversal(root->right, inorderArr);
        return;
    }

    int kthSmallest(TreeNode *root, int k)
    {
        if (!root)
            return 0;
        vector<int> inorderArr;
        Inorder_Traversal(root, inorderArr);
        return inorderArr[k - 1];
    }
};
// @lc code=end
