class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        vector<unordered_set<char>> rowDupes(9);
        vector<unordered_set<char>> colDupes(9);
        for (int row=0;row<board.size();row+=3)
        {
            for (int col=0;col<board[0].size();col+=3)
            {
                unordered_set<char> gridDupes;
                for (int rowOffset=0;rowOffset<3;rowOffset++)
                {
                    for (int colOffset=0;colOffset<3;colOffset++)
                    {
                        if (board[row + rowOffset][col + colOffset] == '.')
                        {
                            continue;
                        }

                        if (gridDupes.find(board[row + rowOffset][col + colOffset]) != gridDupes.end())
                        {
                            return false;
                        }
                        gridDupes.insert(board[row + rowOffset][col + colOffset]);

                        if (rowDupes[row + rowOffset].find(board[row + rowOffset][col + colOffset]) != rowDupes[row + rowOffset].end())
                        {
                            return false;
                        }
                        rowDupes[row + rowOffset].insert(board[row + rowOffset][col + colOffset]);

                        if (colDupes[col + colOffset].find(board[row + rowOffset][col + colOffset]) != colDupes[col + colOffset].end())
                        {
                            return false;
                        }
                        colDupes[col + colOffset].insert(board[row + rowOffset][col + colOffset]);
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