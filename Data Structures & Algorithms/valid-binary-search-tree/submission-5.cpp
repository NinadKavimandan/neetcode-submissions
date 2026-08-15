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
    bool traverse(TreeNode* root, int min, int max)
    {
        if (root != nullptr)
        {
            if (root->val > min && root->val < max)
            {
                return traverse(root->left, min, root->val) && traverse(root->right, root->val, max);
            }
            else
            {
                return false;
            }
        }

        return true;
    }

    bool isValidBST(TreeNode* root)
    {
        return traverse(root, INT_MIN, INT_MAX);
    }
};

/*

each BST element must fall into a range of (min, max) depending on the side of the tree its on, use that to determine if its a BST without extra space

*/