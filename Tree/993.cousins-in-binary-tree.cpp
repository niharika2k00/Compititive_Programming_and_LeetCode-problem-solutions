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
    // --------------------------------------
    //    USING RECURSIVE METHOD   Method - 1
    // --------------------------------------
    int depthFinder(TreeNode *root, int level, int data)
    {
        int left, right;
        if (!root)
            return 0;
        if (root->val == data)
            return level;

        left = depthFinder(root->left, level + 1, data);
        if (left)
            return left;
        right = depthFinder(root->right, level + 1, data);
        return right;
    }

    TreeNode *parentFinder(TreeNode *root, int data)
    {
        TreeNode *left, *right;
        if (root == NULL)
            return NULL;

        if (root->left && root->left->val == data || root->right && root->right->val == data)
            return root;

        left = parentFinder(root->left, data);
        if (left)
            return left;
        right = parentFinder(root->right, data);
        return right;
    }

    bool isCousins(TreeNode *root, int x, int y)
    {
        bool result = false;

        if (root == NULL)
            return false;

        result = (depthFinder(root, 0, x) == depthFinder(root, 0, y)) && (parentFinder(root, x) != parentFinder(root, y));
        return result;
    }

    // --------------------------------------
    //    USING LEVEL ORDER TRAVERSAL   Method - 2
    // --------------------------------------
    /*  bool isCousins(TreeNode *root, int x, int y)
     {
         bool result = false;

         if (root == NULL)
             return false;

         queue<TreeNode *> Q;
         TreeNode *parentX, *parentY;
         int depthX, depthY, level = 0;

         Q.push(root);

         while (!Q.empty())
         {
             int len = Q.size();
             level++;
             for (int i = 0; i < len; i++)
             {
                 TreeNode *currNode = Q.front();
                 Q.pop();

                 if (currNode->left)
                 {
                     if (currNode->left->val == x)
                     {
                         parentX = currNode;
                         depthX = level;
                     }
                     else if (currNode->left->val == y)
                     {
                         parentY = currNode;
                         depthY = level;
                     }
                     Q.push(currNode->left);
                 }

                 if (currNode->right)
                 {
                     if (currNode->right->val == x)
                     {
                         parentX = currNode;
                         depthX = level;
                     }
                     else if (currNode->right->val == y)
                     {
                         parentY = currNode;
                         depthY = level;
                     }
                     Q.push(currNode->right);
                 }
             }
         }

         if (parentX != parentY && depthX == depthY)
             return true;
         return false;
     } */
};
// @lc code=end
