class Solution {
public:
    bool dfs (int current, vector<bool>& visited, vector<vector<int>>& adjList, int& nodesProcessed, int parent)
    {
        visited[current] = true;
        nodesProcessed++;

        for (int next : adjList[current])
        {
            if (next != parent)
            {
                if (visited[next])
                {
                    return false;
                }

                dfs(next, visited, adjList, nodesProcessed, current);
            }
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> adjList(n, vector<int>());
        vector<bool> visited(n, false);
        int nodesProcessed = 0;

        for (vector<int>& edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        if (!dfs(0, visited, adjList, nodesProcessed, -1))
        {
            return false;
        }

        return nodesProcessed == n;
    }
};

/*

directed acyclic graph = tree, basically detect if there's cycle.

how do we detect a cycle though? may be do a dfs on each node you are connected to, if you ever encounter a node you already have seen before, it means you have cycled?

*/