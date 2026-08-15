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
    vector<int> rightSideView(TreeNode* root)
    {
        queue<TreeNode*> nodeQueue;
        vector<int> response;

        if (root != nullptr)
        {
            nodeQueue.push(root);
        }

        while (!nodeQueue.empty())
        {
            int nodesInTheLevel = nodeQueue.size();

            for (int i=0;i < nodesInTheLevel - 1;i++)
            {
                TreeNode* temp = nodeQueue.front();
                
                if (temp->left != nullptr)
                {
                    nodeQueue.push(temp->left);
                }

                if (temp->right != nullptr)
                {
                    nodeQueue.push(temp->right);
                }
                nodeQueue.pop();
            }

            TreeNode* temp = nodeQueue.front();
            response.push_back(temp->val);

            if (temp->left != nullptr)
            {
                nodeQueue.push(temp->left);
            }

            if (temp->right != nullptr)
            {
                nodeQueue.push(temp->right);
            }

            nodeQueue.pop();
        }

        return response;
    }
};

/*

basically level order traversal, just get the right-most elements.

*/