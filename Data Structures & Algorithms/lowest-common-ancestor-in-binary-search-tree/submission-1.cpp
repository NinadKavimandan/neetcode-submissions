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
        stack<TreeNode*> pStack;
        stack<TreeNode*> qStack;

        // look for p first
        TreeNode* iter = root;
        while (iter != p)
        {
            pStack.push(iter);
            if (p->val > iter->val)
            {
                iter = iter->right;
            }
            else
            {
                iter = iter->left;
            }
        }
        pStack.push(iter);

        // look for q now
        iter = root;
        while (iter != q)
        {
            qStack.push(iter);
            if (q->val > iter->val)
            {
                iter = iter->right;
            }
            else
            {
                iter = iter->left;
            }
        }
        qStack.push(iter);

        while (pStack.size() > qStack.size())
        {
            pStack.pop();
        }

        while (pStack.size() < qStack.size())
        {
            qStack.pop();
        }

        // not handling nullptr here as the root is guaranteed to be the ancestor
        while (pStack.top() != qStack.top())
        {
            pStack.pop();
            qStack.pop();
        }

        return pStack.top();
    }
};

/*

path taken to reach a unique node is always unique for a bst. Maintain both paths in a stack, pop from the larger one till their size matches, then pop from both till same node is the top of the stack. That node would be the lowest common ancestor.

*/