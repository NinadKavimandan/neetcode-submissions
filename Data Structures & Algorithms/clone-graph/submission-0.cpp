/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs (Node* node, unordered_set<int>& visited, unordered_map<int, Node*>& cloneNodeMap)
    {
        visited.insert(node->val);
        cloneNodeMap[node->val] = new Node(node->val);

        for (Node* neighbor : node->neighbors)
        {
            if (visited.find(neighbor->val) == visited.end())
            {
                dfs(neighbor, visited, cloneNodeMap);
            }

            cloneNodeMap[node->val]->neighbors.push_back(cloneNodeMap[neighbor->val]);
        }
    }

    Node* cloneGraph(Node* node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        unordered_map<int, Node*> cloneNodeMap;
        unordered_set<int> visited;
        dfs(node, visited, cloneNodeMap);

        return cloneNodeMap[node->val];
    }
};

/*

its a connected graph, so traversing from any node should take us through all nodes eventually.

each node value is numbered to 1 to n, for n nodes, this makes it easier to store the nodes already cloned by the node value.

to start with, go through each node and its neighbours list, for each neighbor, traverse recursively till you reach the end of the graph, maintain a visited set to avoid duplicate traversals, also create clone of each node you visit. on return from recursion, populate adjacency lists with the clones you created. maintain the clones in a map for quick retrieval.

*/