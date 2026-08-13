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
    void swapSubTrees(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        swapSubTrees(root->left);
        swapSubTrees(root->right);
    }

    TreeNode* invertTree(TreeNode* root) 
    {
        swapSubTrees(root);
        return root;
    }
};

/*

for each node, swap its left and right subtrees.

*/