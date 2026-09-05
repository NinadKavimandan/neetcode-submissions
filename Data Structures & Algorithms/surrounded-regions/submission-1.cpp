class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void bfs (vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col)
    {
        vector<pair<int, int>> nodes;
        queue<pair<int, int>> nodeQueue;
        bool isSafe = false;
        nodeQueue.push({row, col});

        while (!nodeQueue.empty())
        {
            pair<int, int>& node = nodeQueue.front();
            nodes.push_back({node.first, node.second});
            if (node.first == 0 || node.first == board.size() - 1 || node.second == 0 || node.second == board[0].size() - 1)
            {
                isSafe = true;
            }

            for (pair<int, int>& direction : directions)
            {
                int newRow = node.first + direction.first;
                int newCol = node.second + direction.second;

                if (newRow > -1 && newRow < board.size() && newCol > -1 && newCol < board[0].size() && board[newRow][newCol] == 'O' && !visited[newRow][newCol])
                {
                    visited[newRow][newCol] = true;
                    nodeQueue.push({newRow, newCol});
                }
            }

            nodeQueue.pop();
        }

        if (!isSafe)
        {
            for (pair<int, int>& node : nodes)
            {
                board[node.first][node.second] = 'X';
            }
        }
    }

    void solve(vector<vector<char>>& board) 
    {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for (int row = 0;row < board.size();row++)
        {
            for (int col = 0;col < board[0].size();col++)
            {
                if (board[row][col] == 'O' && !visited[row][col])
                {
                    visited[row][col] = true;
                    bfs(board, visited, row, col);
                }
            }
        }
    }
};

/*

for each 'O', perform bfs in all directions, keep track of all nodes you have encountered on the way. If you reach boundary, the region is safe, let the 'O' be 'O', otherwise mark them all as 'X'.

*/