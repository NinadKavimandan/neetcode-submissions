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
    int computeMaxPathSum(TreeNode* root, int& globalMax)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int leftSum = computeMaxPathSum(root->left, globalMax);
        int rightSum = computeMaxPathSum(root->right, globalMax);
        int maxSum = root->val + max(leftSum, rightSum);
        globalMax = max(globalMax, root->val + leftSum + rightSum);
        return max(maxSum, 0);
    }

    int maxPathSum(TreeNode* root)
    {
        int maxSum = INT_MIN;
        computeMaxPathSum(root, maxSum);
        return maxSum;
    }
};

/*

bottom up approach, compute sum of each subtree, this should include any and every path.

write a function that return sum per each subtree recursively.

                 5
            4         8
        11    n    13     4
    4.      7     2.   n. n.    n
1.     n  n    n  n.   n

*/