class Solution {
public:
    bool iterate (vector<vector<char>>& board, string& word, int curCharPos, int cellRow, int cellCol)
    {
        if (curCharPos == word.size())
        {
            return true;
        }

        if (cellRow < 0 || cellRow >= board.size() || cellCol < 0 || cellCol >= board[0].size())
        {
            return false;
        }

        if (board[cellRow][cellCol] == word[curCharPos])
        {
            char temp = board[cellRow][cellCol];
            board[cellRow][cellCol] = '.';
            bool result = iterate(board, word, curCharPos + 1, cellRow + 1, cellCol) || iterate(board, word, curCharPos + 1, cellRow, cellCol + 1) || iterate(board, word, curCharPos + 1, cellRow - 1, cellCol) || iterate(board, word, curCharPos + 1, cellRow, cellCol - 1);
            board[cellRow][cellCol] = temp;
            return result;
        }

        return false;
    }

    bool exist (vector<vector<char>>& board, string word)
    {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int row = 0;row < board.size();row++)
        {
            for (int col = 0;col < board[0].size();col++)
            {
                if (iterate(board, word, 0, row, col))
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