class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        queue<vector<int>> fruitQueue;
        int minMinutes = 0;
        int freshFruitCount = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        for (int row = 0;row < grid.size();row++)
        {
            for (int col = 0;col < grid[0].size();col++)
            {
                if (grid[row][col] == 1)
                {
                    freshFruitCount++;
                }
                else if (grid[row][col] == 2)
                {
                    fruitQueue.push({row, col, 0});
                }
            }
        }

        while (!fruitQueue.empty())
        {
            vector<int>& fruit = fruitQueue.front();
            minMinutes = max(minMinutes, fruit[2]);
            for (pair<int, int>& direction : directions)
            {
                int newRow = fruit[0] + direction.first;
                int newCol = fruit[1] + direction.second;
                int newMinutes = fruit[2] + 1;

                if (newRow > -1 && newRow < grid.size() && newCol > -1 && newCol < grid[0].size() && grid[newRow][newCol] == 1)
                {
                    freshFruitCount--;
                    grid[newRow][newCol] = 2;
                    fruitQueue.push({newRow, newCol, newMinutes});
                }
            }

            fruitQueue.pop();
        }

        return freshFruitCount == 0 ? minMinutes : -1;
    }
};

/*

rotting spreads every minute to all neighboring fresh fruits, this is analogous to traversing level order in bfs. the number of steps taken to reach the last fruit is the minimum minutes required for the grid to run out of fresh fruits. pre-compute the count of fresh fruits beforehand and update the count everytime you mark a fruit as rotten. if the count reaches 0, return the minutes, otherwise -1.

*/