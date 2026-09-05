class Solution {
public:
    void solve(vector<vector<char>>& board)
    {
        queue<pair<int, int>> nodeQueue;
        int rows = board.size() - 1;
        int cols = board[0].size() - 1;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // only add bordering 'O' to the queue
        for (int row = 0;row <= rows;row++)
        {
            if (board[row][0] == 'O')
            {
                visited[row][0] = true;
                nodeQueue.push({row, 0});
            }
            if (board[row][cols] == 'O')
            {
                visited[row][cols] = true;
                nodeQueue.push({row, cols});
            }
        }

        for (int col = 0;col <= cols;col++)
        {
            if (board[0][col] == 'O')
            {
                visited[0][col] = true;
                nodeQueue.push({0, col});
            }
            if (board[rows][col] == 'O')
            {
                visited[rows][col] = true;
                nodeQueue.push({rows, col});
            }
        }

        while (!nodeQueue.empty())
        {
            pair<int, int>& node = nodeQueue.front();

            for (pair<int, int>& direction : directions)
            {
                int newRow = node.first + direction.first;
                int newCol = node.second + direction.second;

                if (newRow > -1 && newRow <= rows && newCol > -1 && newCol <= cols && board[newRow][newCol] == 'O' && !visited[newRow][newCol])
                {
                    visited[newRow][newCol] = true;
                    nodeQueue.push({newRow, newCol});
                }
            }

            nodeQueue.pop();
        }

        for (int row = 1;row <= rows;row++)
        {
            for (int col = 1;col <= cols;col++)
            {
                if (!visited[row][col])
                {
                    board[row][col] = 'X';
                }
            }
        }
    }
};

/*

for each 'O', perform bfs in all directions, keep track of all nodes you have encountered on the way. If you reach boundary, the region is safe, let the 'O' be 'O', otherwise mark them all as 'X'.

A simpler approach is to start with only 'O's on the edge, and create a set out of the 'O' nodes possible. Then mark every 'O' not from that set as 'X'.

*/