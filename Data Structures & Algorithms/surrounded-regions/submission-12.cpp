class Solution {
public:
    void solve(vector<vector<char>>& board)
    {
        queue<pair<int, int>> nodeQueue;
        int rows = board.size() - 1;
        int cols = board[0].size() - 1;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // only add bordering 'O' to the queue
        for (int row = 0;row <= rows;row++)
        {
            if (board[row][0] == 'O')
            {
                board[row][0] = '.';
                nodeQueue.push({row, 0});
            }
            if (board[row][cols] == 'O')
            {
                board[row][cols] = '.';
                nodeQueue.push({row, cols});
            }
        }

        for (int col = 0;col <= cols;col++)
        {
            if (board[0][col] == 'O')
            {
                board[0][col] = '.';
                nodeQueue.push({0, col});
            }
            if (board[rows][col] == 'O')
            {
                board[rows][col] = '.';
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

                if (newRow > -1 && newRow <= rows && newCol > -1 && newCol <= cols && board[newRow][newCol] == 'O')
                {
                    board[newRow][newCol] = '.';
                    nodeQueue.push({newRow, newCol});
                }
            }

            nodeQueue.pop();
        }

        for (int row = 0;row <= rows;row++)
        {
            for (int col = 0;col <= cols;col++)
            {
                if (board[row][col] == 'O')
                {
                    board[row][col] = 'X';
                }
                else if (board[row][col] == '.')
                {
                    board[row][col] = 'O';
                }
            }
        }
    }
};

/*

for each 'O', perform bfs in all directions, keep track of all nodes you have encountered on the way. If you reach boundary, the region is safe, let the 'O' be 'O', otherwise mark them all as 'X'.

A simpler approach is to start with only 'O's on the edge, and create a set out of the 'O' nodes possible. Then mark every 'O' not from that set as 'X'.

*/