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
            pacificReachable[row][0] = true;
            nodeQueue.push({row, 0});
        }

        for (int col = 0;col < heights[0].size();col++)
        {
            pacificReachable[0][col] = true;
            nodeQueue.push({0, col});
        }

        while (!nodeQueue.empty())
        {
            pair<int, int> node = nodeQueue.front();
            for (pair<int, int>& direction : directions)
            {
                int newRow = node.first + direction.first;
                int newCol = node.second + direction.second;

                if (newRow > -1 && newRow < heights.size() && newCol > -1 && newCol < heights[0].size() && !pacificReachable[newRow][newCol] && heights[newRow][newCol] >= heights[node.first][node.second])
                {
                    pacificReachable[newRow][newCol] = true;
                    nodeQueue.push({newRow, newCol});
                }
            }

            nodeQueue.pop();
        }

        // all atlantic boundaries
        for (int row = 0;row < heights.size();row++)
        {
            atlanticReachable[row][heights[0].size() - 1] = true;
            nodeQueue.push({row, heights[0].size() - 1});
        }

        for (int col = 0;col < heights[0].size();col++)
        {
            atlanticReachable[heights.size() - 1][col] = true;
            nodeQueue.push({heights.size() - 1, col});
        }

        while (!nodeQueue.empty())
        {
            pair<int, int> node = nodeQueue.front();
            for (pair<int, int>& direction : directions)
            {
                int newRow = node.first + direction.first;
                int newCol = node.second + direction.second;

                if (newRow > -1 && newRow < heights.size() && newCol > -1 && newCol < heights[0].size() && !atlanticReachable[newRow][newCol] && heights[newRow][newCol] >= heights[node.first][node.second])
                {
                    atlanticReachable[newRow][newCol] = true;
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
