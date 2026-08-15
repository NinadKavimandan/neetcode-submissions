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
    void traverse (TreeNode* root, int maxSoFar, int& numberOfGoodNodes)
    {
        if (root->val >= maxSoFar)
        {
            numberOfGoodNodes++;
            maxSoFar = root->val;
        }

        if (root->left != nullptr)
        {
            traverse(root->left, maxSoFar, numberOfGoodNodes);
        }

        if (root->right != nullptr)
        {
            traverse(root->right, maxSoFar, numberOfGoodNodes);
        }
    }

    int goodNodes(TreeNode* root)
    {
        int numberOfGoodNodes = 0;

        if (root != nullptr)
        {
            traverse(root, root->val, numberOfGoodNodes);
        }

        return numberOfGoodNodes;
    }
};
