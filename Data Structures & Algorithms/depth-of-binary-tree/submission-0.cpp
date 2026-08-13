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
    int maximumDepth = 0;

    void traverseWithDepth(TreeNode* root, int depth)
    {
        if (root == nullptr)
        {
            return;
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            maximumDepth = max(maximumDepth, depth);
        }

        traverseWithDepth(root->left, depth+1);
        traverseWithDepth(root->right, depth+1);
    }

    int maxDepth(TreeNode* root) 
    {
        traverseWithDepth(root, 1);
        return maximumDepth;
    }
};

/*

maximum depth would be at one of the leaf nodes, traverse to each leaf node and compute the depth based on the depth of its parent.

*/