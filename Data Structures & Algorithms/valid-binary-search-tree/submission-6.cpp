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
    bool traverse(TreeNode* root, TreeNode* minNode, TreeNode* maxNode)
    {
        if (root != nullptr)
        {
            if ((minNode != nullptr && minNode->val >= root->val) || (maxNode != nullptr && maxNode->val <= root->val))
            {
                return false;
            }

            return traverse(root->left, minNode, root) && traverse(root->right, root, maxNode);
        }

        return true;
    }

    bool isValidBST(TreeNode* root)
    {
        return traverse(root, nullptr, nullptr);
    }
};

/*

each BST element must fall into a range of (min, max) depending on the side of the tree its on, use that to determine if its a BST without extra space

*/