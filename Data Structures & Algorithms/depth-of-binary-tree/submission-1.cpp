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

class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        if (root == nullptr)
        {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }

        int leftDepth = 0;
        if (root->left != nullptr)
        {
            leftDepth = maxDepth(root->left);
        }

        int rightDepth = 0;
        if (root->right != nullptr)
        {
            rightDepth = maxDepth(root->right);
        }

        return 1 + max(leftDepth, rightDepth);
    }
};

/*

maximum depth would be at one of the leaf nodes, traverse to each leaf node and compute the depth based on the depth of its parent.

*/