class Solution {
public:
    typedef struct Trie
    {
        vector<Trie*> next;
        bool wordEnd;

        Trie(): next(vector<Trie*>(26, nullptr)), wordEnd(false) {}
    } Trie;

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void buildTrie (Trie* root, vector<string>& words)
    {
        Trie* iter = root;
        for (string& word : words)
        {
            for (char c : word)
            {
                if (iter->next[c - 'a'] == nullptr)
                {
                    iter->next[c - 'a'] = new Trie();
                }

                iter = iter->next[c - 'a'];
            }

            iter->wordEnd = true;
            iter = root;
        }
    }

    void find (vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col, Trie* root, string& curString, vector<string>& response)
    {
        if (root == nullptr)
        {
            return;
        }

        if (root->wordEnd)
        {
            response.push_back(curString);
            root->wordEnd = false;
        }

        visited[row][col] = true;

        for (pair<int, int>& direction : directions)
        {
            int newRow = row + direction.first;
            int newCol = col + direction.second;

            if (newRow > -1 && newRow < board.size() && newCol > -1 && newCol < board[0].size() && !visited[newRow][newCol] && root->next[board[newRow][newCol] - 'a'] != nullptr)
            {
                curString.push_back(board[newRow][newCol]);
                find(board, visited, newRow, newCol, root->next[board[newRow][newCol] - 'a'], curString, response);
                curString.pop_back();
            }
        }
        visited[row][col] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        Trie* root = new Trie();
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        vector<string> response;
        string temp = "";
        buildTrie(root, words);

        for (int row = 0;row < board.size();row++)
        {
            for (int col = 0;col < board[0].size();col++)
            {
                Trie* iter = root->next[board[row][col] - 'a'];

                if (iter != nullptr)
                {
                    temp.push_back(board[row][col]);
                    find(board, visited, row, col, iter, temp, response);
                    temp.pop_back();
                }
            }
        }

        return response;
    }
};

/*

use backtracking to traverse the grid. And store words in a Trie, to make search simpler.

*/