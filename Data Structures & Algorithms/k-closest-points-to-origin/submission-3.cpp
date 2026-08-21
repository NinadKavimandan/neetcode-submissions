class Solution {
public:
    struct CustomComparator
    {
        bool operator()(const pair<long long, int>& a, const pair<long long, int>& b)
        {
            return a.first < b.first;
        };
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, CustomComparator> maxHeap;

        for (int i=0;i < points.size();i++)
        {
            long long distance = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            maxHeap.push({distance, i});

            if (maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }

        vector<vector<int>> response;

        while (!maxHeap.empty())
        {
            response.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }

        return response;
    }
};

/*

use a max heap to maintain k points closest to the origin
maintain <distance, index in points vector> with each entry in the heap to avoid recomputation and fast lookup.

*/