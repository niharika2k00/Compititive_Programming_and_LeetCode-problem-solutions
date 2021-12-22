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
    int PreorderTraversal_1(TreeNode *root, int sum)
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
    int totalSum = 0;
    void PreorderTraversal_2(Traversal *root, string str)
    {
        if (!root)
            return;

        if (!root->left && !root->right)
        {
            totalSum = totalSum + stoi(str + to_string(root->val), nullptr, 2); // stoi(string, position, int base)
            return;
        }

        PreorderTraversal_2(root->left, str + to_string(root->val));
        PreorderTraversal_2(root->right, str + to_string(root->val));
    }

    int sumRootToLeaf(TreeNode *root)
    {
        string str = "";
        int sum = 0;

        // return PreorderTraversal_1(root, sum);

        PreorderTraversal_2(root, str);
        return totalSum;
    }
};
// @lc code=end
