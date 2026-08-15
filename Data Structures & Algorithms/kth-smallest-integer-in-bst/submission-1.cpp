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
    void traverse (TreeNode* root, int& kth, int& k)
    {
        if (k == 0)
        {
            return;
        }

        if (root != nullptr)
        {
            traverse(root->left, kth, k);
            if (k == 0)
            {
                return;
            }

            k--;
            kth = root->val;
            traverse(root->right, kth, k);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        int response = root->val;

        traverse(root, response, k);

        return response;
    }
};

/*

inorder traversal, use k to maintain the position we are at, once k reaches zero, stop traversing and return the element we stopped at.

*/