class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) 
    {
        queue<pair<int, int>> nodeQueue;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (int row = 0;row < grid.size();row++)
        {
            for (int col = 0;col < grid[0].size();col++)
            {
                if (grid[row][col] == 0)
                {
                    nodeQueue.push({row, col});
                }
            }
        }

        while (!nodeQueue.empty())
        {
            pair<int, int>& top = nodeQueue.front();
            int newDistance = grid[top.first][top.second] + 1;
            for (pair<int, int>& direction : directions)
            {
                int newRow = top.first + direction.first;
                int newCol = top.second + direction.second;
                if (newRow > -1 && newRow < grid.size() && newCol > -1 && newCol < grid[0].size() && grid[newRow][newCol] > newDistance)
                {
                    grid[newRow][newCol] = newDistance;
                    nodeQueue.push({newRow, newCol});
                }
            }
            nodeQueue.pop();
        }
    }
};

/*

iterate through the grid, for each treasure cell, perform a flood fill in 4 directions, while maintaining the number of cells traversed to get to each cell. update the cell value with minimum of its own value and the cells traversed so far, this gives us the shortest distance from the nearest cell.

we can bound this traversal by stopping the search if the current value is less than the number of cells traversed, as the number won't get any better even if we traverse further.

*/