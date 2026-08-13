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
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }

        bool isNodeSame = false;
        if (p != nullptr && q != nullptr)
        {
            if (p->val == q->val)
            {
                isNodeSame = true;
            }
        }
        else
        {
            return false;
        }

        return isNodeSame & isSameTree(p->left, q->left) & isSameTree(p->right, q->right);
    }
};

/*

traverse in same direction for both nodes, if p & q are not equal, return false

*/