/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
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
 * https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
 *
 */
class Solution
{
public:
    TreeNode *CreateBST(TreeNode *NewNode, int data)
    {
        if (NewNode == NULL)
            return NewNode = new TreeNode(data);

        if (data < NewNode->val)
            NewNode->left = CreateBST(NewNode->left, data);

        if (data > NewNode->val)
            NewNode->right = CreateBST(NewNode->right, data);

        return NewNode;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        //   ROOT    LEFT    RIGHT
        int i, len = preorder.size();
        TreeNode *NewNode = new TreeNode(preorder[0]);
        NewNode->left = NewNode->right = NULL;

        if (len == 1)
            return NewNode;

        for (i = 1; i < len; i++)
            CreateBST(NewNode, preorder[i]);

        return NewNode;
    }
};
// @lc code=end
