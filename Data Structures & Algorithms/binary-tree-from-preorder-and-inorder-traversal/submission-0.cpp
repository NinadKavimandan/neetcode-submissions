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
    TreeNode* build (vector<int>& preorder, unordered_map<int, int>& inorderMap, int& preorderIter, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preorderIter]);
        int rootLocation = inorderMap[root->val];
        preorderIter++;

        root->left = build(preorder, inorderMap, preorderIter, left, rootLocation - 1);
        root->right = build(preorder, inorderMap, preorderIter, rootLocation + 1, right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        if (preorder.size() == 0)
        {
            return nullptr;
        }

        unordered_map<int, int> inorderMap;
        int totalNodes = preorder.size();
        int preorderIter = 0;

        for (int i=0;i<totalNodes;i++)
        {
            inorderMap[inorder[i]] = i;
        }

        return build(preorder, inorderMap, preorderIter, 0, totalNodes - 1);
    }
};

/*

use pre-order to determine root, use in-order to determine left and right subtrees.
use a reverse map of value vs index in inorder list for faster lookup.

we basically need to calculate left and right node for each.

*/