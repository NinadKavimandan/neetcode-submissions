class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void computeArea (vector<vector<int>>& grid, int row, int col, int& area)
    {
        area++;
        grid[row][col] = 0;

        for (pair<int, int>& direction : directions)
        {
            int newRow = row + direction.first;
            int newCol = col + direction.second;

            if (newRow > - 1 && newRow < grid.size() && newCol > -1 && newCol < grid[0].size() && grid[newRow][newCol] == 1)
            {
                computeArea(grid, newRow, newCol, area);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int maxArea = 0;

        for (int row = 0;row < grid.size();row++)
        {
            for (int col = 0;col < grid[0].size();col++)
            {
                if (grid[row][col] == 1)
                {
                    int area = 0;
                    computeArea(grid, row, col, area);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};

/*

traverse through grid, if you encounter 1, that's the start of an island. traverse the island in 4 directions, as long as you see 1. Keep track of the 1s encountered so far, this becomes the area of the island. Mark each 1 you visited as 0 to avoid duplicate processing. Maintain a rolling max based on the areas of islands you have encountered so far.

*/