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
    int globalMax = 0;

    int depth(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }

        int leftLength = depth(root->left);
        int rightLength = depth(root->right);

        int totalLength = leftLength + rightLength;
        globalMax = max(globalMax, totalLength);
        return 1 + max(leftLength, rightLength);
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        depth(root);

        return globalMax;
    }
};

/*

maximum length should be the total of longest edge on left and right subtrees + 1

*/