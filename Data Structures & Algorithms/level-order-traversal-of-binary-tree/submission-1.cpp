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
        queue<pair<TreeNode*, int>> nodeQueue;

        if (root != nullptr)
        {
            nodeQueue.push({root, 0});
        }
        else
        {
            return {};
        }

        vector<int> tempList;
        int curLevel = 0;
        while (!nodeQueue.empty())
        {
            auto& temp = nodeQueue.front();

            if (curLevel != temp.second)
            {
                response.push_back(tempList);
                tempList.clear();
                curLevel++;
            }

            tempList.push_back(temp.first->val);
            if (temp.first->left != nullptr)
            {
                nodeQueue.push({temp.first->left, temp.second + 1});
            }
            if (temp.first->right != nullptr)
            {
                nodeQueue.push({temp.first->right, temp.second + 1});
            }

            nodeQueue.pop();
        }

        response.push_back(tempList);

        return response;
    }
};

/*

use a queue to store nodes from each level, add left and right children of each node to the queue, along with the level of current node + 1, use the level marker to identify start and end of sublists.  

*/