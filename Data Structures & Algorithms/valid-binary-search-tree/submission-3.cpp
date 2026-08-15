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
    void traverse(TreeNode* root, vector<int>& elements)
    {
        if (root != nullptr)
        {
            traverse(root->left, elements);
            elements.push_back(root->val);
            traverse(root->right, elements);
        }
    }

    bool isValidBST(TreeNode* root)
    {
        vector<int> elements;
        traverse(root, elements);

        for (int i=1;i<elements.size();i++)
        {
            if (elements[i] <= elements[i-1])
            {
                return false;
            }
        }

        return true;
    }
};

/*

in order traversal of a BST always gives sorted values, store and see if the non-decreasing sequence ever breaks

*/