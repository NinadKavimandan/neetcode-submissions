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
    int goodNodes(TreeNode* root)
    {
        queue<pair<TreeNode*, int>> nodeQueue;
        int totalGoodNodes = 0;

        if (root != nullptr)
        {
            nodeQueue.push({root, root->val});
        }

        while (!nodeQueue.empty())
        {
            auto temp = nodeQueue.front();
            int largestSoFar = temp.second;

            if (temp.first->val >= temp.second)
            {
                largestSoFar = temp.first->val;
                totalGoodNodes++;
            }

            if (temp.first->left != nullptr)
            {
                nodeQueue.push({temp.first->left, largestSoFar});
            }

            if (temp.first->right != nullptr)
            {
                nodeQueue.push({temp.first->right, largestSoFar});
            }

            nodeQueue.pop();
        }

        return totalGoodNodes;
    }
};

/*

a node is good if its not less than the largest node in the path so far.

*/