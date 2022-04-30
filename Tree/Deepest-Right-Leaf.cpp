
//  Link :
// https: // www.codingninjas.com/codestudio/problems/deepest-right-leaf_764143?leftPanelTab=1

int currLevel = 0;
BinaryTreeNode<int> *res = NULL;

void Helper(BinaryTreeNode<int> *root, int level, bool isRight)
{
    if (!root)
        return;

    // 	 check is leaf node & right
    if (isRight && !root->left && !root->right && level >= currLevel)
    {
        currLevel = level;
        res = root;
    }

    Helper(root->left, level + 1, false);
    Helper(root->right, level + 1, true);
}

BinaryTreeNode<int> *deepestRightLeaf(BinaryTreeNode<int> *root)
{
    // Write your code here.
    if (!root)
        return NULL;

    Helper(root, 0, false);
    return res;
}
