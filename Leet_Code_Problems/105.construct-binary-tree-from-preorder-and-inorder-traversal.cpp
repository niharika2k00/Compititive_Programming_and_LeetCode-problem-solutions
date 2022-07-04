/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

class Solution
{
public:
    TreeNode *treeCreation(vector<int> &preorder, vector<int> &inorder, int start, int end)
    {
        int preorderIndex = 0, position = 0, i = 0;

        if (start > end)
            return NULL;

        if (start < end)
        {
            //  Creation of a new node  using new
            TreeNode *newNode = new TreeNode(preorder[preorderIndex++]); // preorder[0] = 3

            // Search for the node in the inorder
            for (i = start; i < end; i++)
                if (inorder[i] == newNode->val)
                {
                    position = i;
                    break;
                }

            newNode->left = treeCreation(preorder, inorder, start, position - 1);
            newNode->right = treeCreation(preorder, inorder, position + 1, end);
        }

        return newNode;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        int size = preorder.size() - 1;
        return treeCreation(preorder, inorder, 0, size);
    }
};
// @lc code=end
