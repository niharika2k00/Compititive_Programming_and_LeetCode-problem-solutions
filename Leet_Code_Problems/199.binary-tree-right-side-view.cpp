/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/
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
    void Helper(TreeNode *root, vector<int> &res, int level)
    {
        if (!root)
            return;

        // when the level is iterated 1st its val is taken as we are moving  R -> L direction.
        if (res.size() == level)
            res.push_back(root->val);

        if (root->right)
            Helper(root->right, res, level + 1);

        if (root->left)
            Helper(root->left, res, level + 1);

        return;
    }

    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;

        if (!root)
            return {};

        Helper(root, res, 0);
        return res;
    }
};
// @lc code=end

/*
              Intuition
          -----------------

    - See from the Right Side
    - Means if we do Level order traversal from R -> L, then 1st encountered NODE ll'be seen at RIGHT in that Level.
    - At that time put it into the Data structure.

 */