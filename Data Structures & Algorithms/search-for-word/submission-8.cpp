class Solution {
public:
    void iterate (vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int curCharPos, int cellRow, int cellCol, bool& response)
    {
        if (response)
        {
            return;
        }

        if (curCharPos == word.size())
        {
            response = true;
            return;
        }

        if (cellRow < 0 || cellRow >= board.size() || cellCol < 0 || cellCol >= board[0].size())
        {
            return;
        }

        if (visited[cellRow][cellCol])
        {
            return;
        }

        cout<<board[cellRow][cellCol]<<" - "<<curCharPos<<endl;
        if (board[cellRow][cellCol] == word[curCharPos])
        {
            visited[cellRow][cellCol] = true;
            iterate(board, word, visited, curCharPos + 1, cellRow + 1, cellCol, response);
            iterate(board, word, visited, curCharPos + 1, cellRow, cellCol + 1, response);
            iterate(board, word, visited, curCharPos + 1, cellRow - 1, cellCol, response);
            iterate(board, word, visited, curCharPos + 1, cellRow, cellCol - 1, response);
            visited[cellRow][cellCol] = false;
        }
    }

    bool exist (vector<vector<char>>& board, string word)
    {
        for (int row = 0;row < board.size();row++)
        {
            for (int col = 0;col < board[0].size();col++)
            {
                vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                bool response = false;
                iterate(board, word, visited, 0, row, col, response);
                if (response)
                {
                    return true;
                }
            }
        }

        return false;
    }
};

/*

iterate over the word and use dfs to iterate each path on the board, enter a branch with next character is current matches, otherwise move to next to start search from first character again.

*/