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

class Codec {
public:
    void construct (TreeNode* root, string& serialized)
    {
        serialized += "(";
        
        if (root != nullptr)
        {
            serialized += to_string(root->val);

            string leftNode = serialize(root->left);
            string rightNode = serialize(root->right);

            serialized += leftNode + rightNode;
        }
        serialized += ")";
    }

    // Encodes a tree to a single string.
    // (Element,left,right)
    string serialize(TreeNode* root)
    {
        string serialized;
        construct(root, serialized);
        return serialized;
    }

    TreeNode* getNode (string& data, int& curIter)
    {
        int offset = 0;
        if (data[curIter] == '(' && data[curIter + 1] == ')')
        {
            curIter+=2;
            return nullptr;
        }

        if (data[curIter] == '(')
        {
            curIter++;
            while (data[curIter + offset] != '(')
            {
                offset++;
            }

            TreeNode* root = new TreeNode(stoi(data.substr(curIter, offset)));
            curIter += offset;
            root->left = getNode(data, curIter);
            root->right = getNode(data, curIter);
            curIter++;

            return root;
        }
        
        return nullptr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        int curIter = 0;
        return getNode(data, curIter);
    }
};

/*

use consistent schema - (<element><left><right>)

*/