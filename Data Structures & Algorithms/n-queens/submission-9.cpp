class Solution {
public:
    void generate (vector<string>& board, int n, int row, vector<bool>& unsafeCol, vector<bool>& diag, vector<bool>& altDiag, vector<vector<string>>& response)
    {
        if (row == n)
        {
            response.push_back(board);
            return;
        }

        for (int i=0;i < board.size();i++)
        {
            if (!unsafeCol[i] && !diag[row + i] && !altDiag[row - i + n - 1])
            {
                unsafeCol[i] = true;
                diag[row + i] = true;
                altDiag[row - i + n - 1] = true;
                board[row][i] = 'Q';
                generate(board, n, row + 1, unsafeCol, diag, altDiag, response);
                unsafeCol[i] = false;
                diag[row + i] = false;
                altDiag[row - i + n - 1] = false;
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> response;
        vector<bool> unsafeCol(n, false);
        vector<bool> diag(2*n - 1, false);
        vector<bool> altDiag(2*n - 1, false);
        generate(board, n, 0, unsafeCol, diag, altDiag, response);
        return response;
    }
};

/*

start simple, n queens over nxn board means, no more than 1 queen per row and per column, the queens cannot be diagonally aligned either.

this decreases the search space, go row by row, decide the position of the queen in that row, assume that position and see if you can place the queen in the next row successfully. backtrack if you cannot.

*/
