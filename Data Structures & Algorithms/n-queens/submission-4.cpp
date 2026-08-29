class Solution {
public:
    vector<bool> unsafeRow = {false, false, false, false, false, false, false, false};
    vector<bool> unsafeCol = {false, false, false, false, false, false, false, false};
    vector<bool> diag = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
    vector<bool> altDiag = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
    
    void addQueen (vector<string>& board, int row, int col)
    {
        unsafeRow[row] = true;
        unsafeCol[col] = true;
        diag[row + col] = true;
        altDiag[row - col + 7] = true;
        board[row][col] = 'Q';
    }

    void removeQueen (vector<string>& board, int row, int col)
    {
        unsafeRow[row] = false;
        unsafeCol[col] = false;
        diag[row + col] = false;
        altDiag[row - col + 7] = false;
        board[row][col] = '.';
    }

    bool isSafe (vector<string>& board, int row, int col)
    {
        if (board[row][col] != '.' || unsafeRow[row] || unsafeCol[col] || diag[row + col] || altDiag[row - col + 7])
        {
            return false;
        }

        return true;
    }

    void generate (vector<string>& board, int row, vector<vector<string>>& response)
    {
        if (row == board.size())
        {
            response.push_back(board);
            return;
        }

        for (int i=0;i < board.size();i++)
        {
            if (isSafe(board, row, i))
            {
                addQueen(board, row, i);
                generate(board, row + 1, response);
                removeQueen(board, row, i);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> response;
        generate(board, 0, response);
        return response;
    }
};

/*

start simple, n queens over nxn board means, no more than 1 queen per row and per column, the queens cannot be diagonally aligned either.

this decreases the search space, go row by row, decide the position of the queen in that row, assume that position and see if you can place the queen in the next row successfully. backtrack if you cannot.

*/
