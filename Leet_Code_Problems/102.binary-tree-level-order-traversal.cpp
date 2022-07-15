/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/
 *
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
    //  Iterative BFS using Queue
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int len = q.size();
            vector<int> currLevel;

            for (int i = 0; i < len; i++)
            {
                TreeNode *frontNode = q.front();
                q.pop();
                currLevel.push_back(frontNode->val);

                if (frontNode->left != NULL)
                    q.push(frontNode->left);

                if (frontNode->right != NULL)
                    q.push(frontNode->right);
            }

            res.push_back(currLevel);
        }

        return res;
    }
};
// @lc code=end
