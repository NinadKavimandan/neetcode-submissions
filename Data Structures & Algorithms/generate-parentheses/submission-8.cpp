class Solution {
public:
    void generate (int target, int open, int closed, string& text, vector<string>& response)
    {
        if (text.size() == 2*target)
        {
            response.push_back(text);
        }
        else
        {
            if (open < target)
            {
                text.push_back('(');
                generate(target, open + 1, closed, text, response);
                text.pop_back();
            }

            if (closed < target && closed < open)
            {
                text.push_back(')');
                generate(target, open, closed + 1, text, response);
                text.pop_back();
            }
        }
    }

    vector<string> generateParenthesis(int n)
    {
        string text;
        vector<string> response;
        generate(n, 0, 0, text, response);

        return response;
    }
};

/*

use dfs to generate paranthese strings, maintain open and closed paranthesis count, only add closing bracket is unmatched opening bracket is present

*/