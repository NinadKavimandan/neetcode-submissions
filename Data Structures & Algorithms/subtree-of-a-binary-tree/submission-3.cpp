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
    bool areEqual(TreeNode* root, TreeNode* subRoot)
    {
        if (root == nullptr || subRoot == nullptr)
        {
            return root == subRoot;
        }
        if (root->val == subRoot->val)
        {
            return areEqual(root->left, subRoot->left) && areEqual(root->right, subRoot->right);
        }

        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if (root == nullptr || subRoot == nullptr)
        {
            return false;
        }
        
        if (root->val == subRoot->val)
        {
            if (areEqual(root, subRoot))
            {
                return true;
            }
        }

        bool leftResult = false;
        bool rightResult = false;

        if (root->left != nullptr)
        {
            leftResult = isSubtree(root->left, subRoot);
        }

        if (root->right != nullptr)
        {
            rightResult = isSubtree(root->right, subRoot);
        }

        return leftResult || rightResult;
    }
};

/*

can be viewed as a two step problem, identify the root node of subRoot in root tree, then check if subRoot has all the nodes present in root from that point on.

*/
