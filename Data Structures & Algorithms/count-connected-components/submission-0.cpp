class Solution {
public:
    void dfs (int current, vector<bool>& visited, vector<vector<int>>& adjList)
    {
        visited[current] = true;

        for (int next : adjList[current])
        {
            if (!visited[next])
            {
                dfs(next, visited, adjList);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> adjList(n, vector<int>());
        vector<bool> visited(n, false);
        int connectedComponents = 0;

        for (vector<int>& edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        for (int i = 0;i < n;i++)
        {
            if (!visited[i])
            {
                connectedComponents++;
                dfs(i, visited, adjList);
            }
        }

        return connectedComponents;
    }
};

/*

use dfs to traverse a component fully. to do that, start dfs over every node sequentially, if a node is not already visited, count that as a new component and dfs it.

*/