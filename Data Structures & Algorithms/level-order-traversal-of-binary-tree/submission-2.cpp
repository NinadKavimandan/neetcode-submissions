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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> response;
        queue<TreeNode*> nodeQueue;

        if (root != nullptr)
        {
            nodeQueue.push(root);
        }
        else
        {
            return {};
        }

        vector<int> tempList;
        while (!nodeQueue.empty())
        {
            int nodesInTheLevel = nodeQueue.size();

            while (nodesInTheLevel != 0)
            {
                TreeNode* temp = nodeQueue.front();
                tempList.push_back(temp->val);

                if (temp->left != nullptr)
                {
                    nodeQueue.push(temp->left);
                }
                if (temp->right != nullptr)
                {
                    nodeQueue.push(temp->right);
                }

                nodeQueue.pop();
                nodesInTheLevel--;
            }

            response.push_back(tempList);
            tempList.clear();
        }

        return response;
    }
};

/*

use a queue to store nodes from each level, add left and right children of each node to the queue, along with the level of current node + 1, use the level marker to identify start and end of sublists.  

*/