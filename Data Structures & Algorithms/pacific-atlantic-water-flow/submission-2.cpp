class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        vector<vector<bool>> pacificReachable(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlanticReachable(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<int>> response;
        queue<pair<int, int>> nodeQueue;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        
        // all pacific boundaries
        for (int row = 0;row < heights.size();row++)
        {
            nodeQueue.push({row, 0});
        }

        for (int col = 0;col < heights[0].size();col++)
        {
            nodeQueue.push({0, col});
        }

        while (!nodeQueue.empty())
        {
            pair<int, int> node = nodeQueue.front();
            pacificReachable[node.first][node.second] = true;

            for (pair<int, int>& direction : directions)
            {
                int newRow = node.first + direction.first;
                int newCol = node.second + direction.second;

                if (newRow > -1 && newRow < heights.size() && newCol > -1 && newCol < heights[0].size() && !pacificReachable[newRow][newCol] && heights[newRow][newCol] >= heights[node.first][node.second])
                {
                    nodeQueue.push({newRow, newCol});
                }
            }

            nodeQueue.pop();
        }

        // all atlantic boundaries
        for (int row = 0;row < heights.size();row++)
        {
            nodeQueue.push({row, heights[0].size() - 1});
        }

        for (int col = 0;col < heights[0].size();col++)
        {
            nodeQueue.push({heights.size() - 1, col});
        }

        while (!nodeQueue.empty())
        {
            pair<int, int> node = nodeQueue.front();
            atlanticReachable[node.first][node.second] = true;

            for (pair<int, int>& direction : directions)
            {
                int newRow = node.first + direction.first;
                int newCol = node.second + direction.second;

                if (newRow > -1 && newRow < heights.size() && newCol > -1 && newCol < heights[0].size() && !atlanticReachable[newRow][newCol] && heights[newRow][newCol] >= heights[node.first][node.second])
                {
                    nodeQueue.push({newRow, newCol});
                }
            }

            nodeQueue.pop();
        }

        for (int row = 0;row < heights.size();row++)
        {
            for (int col = 0;col < heights[0].size();col++)
            {
                if (atlanticReachable[row][col] && pacificReachable[row][col])
                {
                    response.push_back({row, col});
                }
            }
        }

        return response;
    }
};

/*

reverse track the movement of water, from boundaries to cells. If a cell can get water from both boundaries, thats one of the cells we are looking for.

*/
