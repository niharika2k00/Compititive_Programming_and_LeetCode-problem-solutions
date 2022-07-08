/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
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
 * https://leetcode.com/problems/most-frequent-subtree-sum/description/
 *
 */
class Solution
{
public:
    int SubtreeSum(unordered_map<int, int> &hashMap, int &maxFreq, TreeNode *root)
    {
        if (!root)
            return 0;

        int leftSum = SubtreeSum(hashMap, maxFreq, root->left);
        int rightSum = SubtreeSum(hashMap, maxFreq, root->right);

        int sum = leftSum + rightSum + root->val;
        hashMap[sum]++; //  stores in the HashMap

        maxFreq = max(maxFreq, hashMap[sum]);

        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        if (!root)
            return {0};

        unordered_map<int, int> hashMap; // for freq storage  [sum , freq]
        int maxFreq = 0;
        vector<int> res;

        cout << SubtreeSum(hashMap, maxFreq, root) << endl;

        for (auto it : hashMap)
        {
            if (it.second == maxFreq)
                res.push_back(it.first);
        }

        return res;
    }
};
// @lc code=end
