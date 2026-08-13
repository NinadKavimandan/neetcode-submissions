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
    int height (TreeNode* root, bool& balanced)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int leftHeight = height(root->left, balanced);
        int rightHeight = height(root->right, balanced);

        if (abs(leftHeight - rightHeight) > 1)
        {
            balanced = false;
        }

        return 1 + max(leftHeight, rightHeight);
        
    }

    bool isBalanced(TreeNode* root)
    {
        bool balanced = true;
        height(root, balanced);

        return balanced;
    }
};

/*

compare height of both subtree at each node, if the condition is not satisfied, the tree is not balanced

*/