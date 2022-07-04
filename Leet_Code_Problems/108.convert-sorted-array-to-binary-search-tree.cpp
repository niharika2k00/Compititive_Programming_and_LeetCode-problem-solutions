/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode *CreateBST(vector<int> arr, int start, int end)
    {
        if (start > end)
            return NULL;

        int mid = (start + end) / 2;
        TreeNode *node = new TreeNode(arr[mid]);

        node->left = CreateBST(arr, start, mid - 1);
        node->right = CreateBST(arr, mid + 1, end);

        return node;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums) // nums is sorted in a strictly increasing order / Inorder Traversal
    {
        int start = 0, end = nums.size() - 1;
        return CreateBST(nums, start, end);
    }
};
// @lc code=end
