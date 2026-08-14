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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        TreeNode* iter = root;
        TreeNode* smaller = p->val > q->val ? q : p;
        TreeNode* larger = p->val < q->val ? q : p;

        while ((p->val > iter->val && q->val > iter->val) || (p->val < iter->val && q->val < iter->val))
        {
            if (p->val > iter->val && q->val > iter->val)
            {
                iter = iter->right;
            }
            else
            {
                iter = iter->left;
            }
        }

        return iter;
    }
};

/*

path taken to reach a unique node is always unique for a bst. Maintain both paths in a stack, pop from the larger one till their size matches, then pop from both till same node is the top of the stack. That node would be the lowest common ancestor.

now that we got it working, lets think of something simpler and lighter. r can only be the ancestor of p and q if p and q are in different subtrees when viewed from r, or if r equals p or q. lets try this approach.

*/