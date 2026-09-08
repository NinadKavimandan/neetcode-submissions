class Solution {
public:
    void isCyclic (vector<vector<int>>& adjList, int node, int parent, vector<bool>& visited, bool& redundant)
    {
        visited[node] = true;

        for (int next : adjList[node])
        {
            if (redundant)
            {
                return;
            }

            if (visited[next])
            {
                if (next == parent)
                {
                    continue;
                }
                
                redundant = true;
                return;
            }
            else
            {
                isCyclic(adjList, next, node, visited, redundant);
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        vector<vector<int>> adjList(edges.size(), vector<int>());
        bool redundant = false;
        for (vector<int>& edge : edges)
        {
            vector<bool> visited(edges.size(), false);
            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
            isCyclic(adjList, edge[0] - 1, -1, visited, redundant);

            if (redundant)
            {
                return edge;
            }
        }

        return vector<int>();
    }
};

/*

use dfs to traverse each path, if you encounter a node already visited, that's a redundant edge. since its a fully connected setup, you can choose any point to discover the redundant edge/s. For appearing last in the edges list, we can probably use extra memory as a boolean map to track what all edges are redundant, return first from right thats redundant.. too complex, just traverse from last node?

*/