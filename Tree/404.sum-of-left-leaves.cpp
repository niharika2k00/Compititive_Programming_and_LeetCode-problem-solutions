/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
    int sum = 0;
    int sumOfLeftLeaves(TreeNode *root)
    {
        // Condition for LEFT LEAF Node.
        if (root->left && root->left->left == NULL and root->left->right == NULL)
            sum = sum + root->left->val;

        if (root->left) // when ! NULL
            sumOfLeftLeaves(root->left);

        if (root->right)
            sumOfLeftLeaves(root->right);

        return sum;
    }
};
//   https://leetcode.com/problems/sum-of-left-leaves/discuss/1626781/C%2B%2B-or-BFS-or-Iterative-or-100.00-Faster
// @lc code=end
