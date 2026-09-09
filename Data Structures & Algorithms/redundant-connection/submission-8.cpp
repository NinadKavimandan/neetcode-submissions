class Solution {
public:
    int find (vector<int>& roots, int node)
    {
        int iter = node;
        while (roots[iter] != iter)
        {
            iter = roots[iter];
        }

        return iter;
    }

    void performUnion (vector<int>& roots, vector<int>& cardinality, int first, int second)
    {
        if (cardinality[first] > cardinality[second])
        {
            roots[second] = first;
            cardinality[first] += cardinality[second];
        }
        else
        {
            roots[first] = second;
            cardinality[second] += cardinality[first];
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        vector<int> roots(edges.size(), -1);
        vector<int> cardinality(edges.size(), 1);

        for (int i=0;i < edges.size();i++)
        {
            roots[i] = i;
        }

        for (vector<int>& edge : edges)
        {
            int root1 = find(roots, edge[0] - 1);
            int root2 = find(roots, edge[1] - 1);
            if (root1 != root2)
            {
                performUnion(roots, cardinality, root1, root2);
            }
            else
            {
                return edge;
            }
        }

        return vector<int>();
    }
};

/*

we want to track what's part of what subset, union find seems like a natural fit. For each (u, v), add them to the larger set amongst the two. If (u, v) are already part of the same set, that's the redundant edge.

*/