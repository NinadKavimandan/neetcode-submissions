class Solution {
public:
    void generate (int target, int open, int closed, string& text, stack<char>& balance, vector<string>& response)
    {
        if (text.size() == 2*target)
        {
            response.push_back(text);
        }
        else
        {
            if (open < target)
            {
                text += '(';
                int newSize = text.size() - 1;
                generate(target, open + 1, closed, text, balance, response);
                text.erase(newSize, 1);
            }

            if (closed < target && closed < open)
            {
                text += ')';
                int newSize = text.size() - 1;
                generate(target, open, closed + 1, text, balance, response);
                text.erase(newSize, 1);
            }
        }
    }

    vector<string> generateParenthesis(int n)
    {
        string text;
        stack<char> balance;
        vector<string> response;
        generate(n, 0, 0, text, balance, response);

        return response;
    }
};

/*

use dfs to generate paranthese strings, also maintain a stack to ensure parentheses balance can be pre-computed

*/