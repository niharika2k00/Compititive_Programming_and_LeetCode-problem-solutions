/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/
 *
 */
class Solution
{
public:
    void preOrder(TreeNode *root, vector<int> &arr)
    {
        if (root == NULL)
            return;

        arr.push_back(root->val);

        if (root->left)
            preOrder(root->left, arr);

        if (root->right)
            preOrder(root->right, arr);
    }

    int getMinimumDifference(TreeNode *root)
    {
        vector<int> arr;
        int res = INT_MAX;

        preOrder(root, arr);
        sort(arr.begin(), arr.end()); //  O (n log n)

        for (int i = 1; i < arr.size(); i++)
            res = min(res, arr[i] - arr[i - 1]);

        return res;
    }
};
// @lc code=end
//    INORDER TRAVERSAL can also be performed as the nodes are present in sorted order.