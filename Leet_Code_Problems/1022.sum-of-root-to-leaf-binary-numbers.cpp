/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
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
 * https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
 *
 */
class Solution
{
public:
    // ----------------------------------------------
    //               METHOD - 1
    // ----------------------------------------------
    int PreorderTraversal_1(TreeNode *root, int sum) //  BFS Traversal
    {
        if (!root)
            return 0;

        sum = (2 * sum) + root->val;
        if (!root->left && !root->right)
            return sum;

        auto left = PreorderTraversal_1(root->left, sum);
        auto right = PreorderTraversal_1(root->right, sum);

        return left + right;
    }

    // ----------------------------------------------
    //               METHOD - 2
    // ----------------------------------------------
    //  stoi(string, position, int base)
    //  to_string ()  -> converts string to integer.
    int totalSum = 0;
    void PreorderTraversal_2(TreeNode *root, string str)
    {
        // Base Case
        if (!root)
            return;

        // Leaf Node(last) -- convert the string to binary
        if (!root->left && !root->right)
        {
            totalSum = totalSum + stoi(str + to_string(root->val), NULL, 2);
            return;
        }

        PreorderTraversal_2(root->left, str + to_string(root->val)); // append the node value
        PreorderTraversal_2(root->right, str + to_string(root->val));
    }

    int sumRootToLeaf(TreeNode *root)
    {
        string str = "";
        int sum = 0;

        return PreorderTraversal_1(root, sum);

        // PreorderTraversal_2(root, str);
        return totalSum;
    }
};
// @lc code=end
