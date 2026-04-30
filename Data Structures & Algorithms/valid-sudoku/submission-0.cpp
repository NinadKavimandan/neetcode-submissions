class Solution {
public:
    bool rowCheck(vector<vector<char>>& board, int row, int col)
    {
        vector<int> cellValues(10, 0);
        if (board[row][col] != '.')
        {
            for (int index=0;index<board[0].size();index++)
            {
                if (index != col && board[row][index] == board[row][col])
                {
                    return false;
                }
            }
        }
        else
        {
            for (int index=0;index<board[0].size();index++)
            {
                if (index != col && board[row][index] != '.')
                {
                    if (cellValues[board[row][index] - '0'] == 1)
                    {
                        return false;
                    }

                    cellValues[board[row][index] - '0']++;
                }
            }
        }

        return true;
    }

    bool colCheck(vector<vector<char>>& board, int row, int col)
    {
        vector<int> cellValues(10, 0);
        if (board[row][col] != '.')
        {
            for (int index=0;index<board.size();index++)
            {
                if (index != row && board[index][col] == board[row][col])
                {
                    return false;
                }
            }
        }
        else
        {
            for (int index=0;index<board.size();index++)
            {
                if (index != row && board[index][col] != '.')
                {
                    if (cellValues[board[index][col] - '0'] == 1)
                    {
                        return false;
                    }
                    cellValues[board[index][col] - '0']++;
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) 
    {
        for (int row=0;row<board.size();row+=3)
        {
            for (int col=0;col<board[0].size();col+=3)
            {
                vector<int> cellValues(10, 0);
                for (int rowOffset=0;rowOffset<3;rowOffset++)
                {
                    for (int colOffset=0;colOffset<3;colOffset++)
                    {
                        if (board[row + rowOffset][col + colOffset] != '.')
                        {
                            if (cellValues[board[row + rowOffset][col + colOffset] - '0'] == 1)
                            {
                                return false;
                            }
                            cellValues[board[row + rowOffset][col + colOffset] - '0']++;
                        }
                    }
                }

                for (int rowOffset=0;rowOffset<3;rowOffset++)
                {
                    for (int colOffset=0;colOffset<3;colOffset++)
                    {
                        if (!rowCheck(board, row + rowOffset, col + colOffset))
                        {
                            return false;
                        }

                        if (!colCheck(board, row + rowOffset, col + colOffset))
                        {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};

/*

oh wow, this is a hard one.
how do you solve sudoku?
traverse cell by cell, may be maintain a list of possible values per cell. if for any of the cell, the possible values list becomes empty, that would mean the cell cannot have any value, thus rendering the sudoku invalid.
the list of possible values can just be an array of 10 values, so 81*10 values.

to compute number of possible values using - row, column, and grid.
move grid to grid for easier computation may be.

why is this the correct answer? getting the actual right value per cell is hard, but you can always guess. If no guess is possible, sudoku is invalid.

*/