class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void traverse (vector<vector<char>>& grid, int row, int col)
    {
        grid[row][col] = '0';
        for (pair<int, int>& direction : directions)
        {
            int newRow = row + direction.first;
            int newCol = col + direction.second;
            
            if (newRow > -1 && newRow < grid.size() && newCol > -1 && newCol < grid[0].size() && grid[newRow][newCol] == '1')
            {
                traverse(grid, newRow, newCol);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int islands = 0;
        for (int row = 0;row < grid.size();row++)
        {
            for (int col = 0;col < grid[0].size();col++)
            {
                if (grid[row][col] == '1')
                {
                    traverse(grid, row, col);
                    islands++;
                }
            }
        }

        return islands;
    }
};

/*

go over each cell, if its 1, consider that as start of an island and update the count, perform dfs till you run out of 1s in 4 directions. mark each 1 as 0 as you perform dfs to ensure all connected 1s are covered and same island won't be counted twice.

*/