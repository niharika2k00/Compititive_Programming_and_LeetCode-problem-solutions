/*
 * @lc app=leetcode id=1382 lang=cpp
 *
 * [1382] Balance a Binary Search Tree
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
    void Inorder_Traversal(TreeNode *root, vector<int> &inorderArr)
    {
        if (root->left)
            Inorder_Traversal(root->left, inorderArr);
        inorderArr.push_back(root->val);
        if (root->right)
            Inorder_Traversal(root->right, inorderArr);
        return;
    }

    TreeNode *BalanceBSTCreate(vector<int> &inorderArr, int start, int end)
    {
        // Base Case
        if (start > end)
            return NULL;

        int mid = (start + end) / 2;
        TreeNode *node = new TreeNode(inorderArr[mid]);

        node->left = BalanceBSTCreate(inorderArr, start, mid - 1);
        node->right = BalanceBSTCreate(inorderArr, mid + 1, end);

        return node;
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        if (!root)
            return NULL;

        vector<int> inorderArr;

        // Inorder Traversal to get the Sorted Array.
        Inorder_Traversal(root, inorderArr);
        int start = 0, end = inorderArr.size() - 1;

        return BalanceBSTCreate(inorderArr, start, end);
    }
};
// @lc code=end
