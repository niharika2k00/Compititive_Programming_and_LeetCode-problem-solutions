/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
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
 * https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
 *
 */
class Solution
{
public:
    int DifferenceMinimization(TreeNode *root, int currMin, int currMax)
    {
        if (!root)
            return abs(currMax - currMin);

        currMin = min(currMin, root->val);
        currMax = max(currMax, root->val);

        int leftSide = DifferenceMinimization(root->left, currMin, currMax);
        int rightSide = DifferenceMinimization(root->right, currMin, currMax);

        return max(leftSide, rightSide);
    }

    // Ancestor means Parent
    int maxAncestorDiff(TreeNode *root)
    {
        if (!root)
            return 0;

        return DifferenceMinimization(root, root->val, root->val);
    }
};
// @lc code=end
