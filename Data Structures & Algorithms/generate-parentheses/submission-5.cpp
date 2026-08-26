class Solution {
public:
    void generate (int target, int open, int closed, string& text, stack<char>& balance, vector<string>& response)
    {
        if (text.size() == 2*target && balance.empty())
        {
            response.push_back(text);
        }
        else
        {
            if (open < target)
            {
                text += '(';
                int newSize = text.size() - 1;
                balance.push('(');
                generate(target, open + 1, closed, text, balance, response);
                balance.pop();
                text.erase(newSize, 1);
            }

            if (closed < target && !balance.empty())
            {
                text += ')';
                int newSize = text.size() - 1;
                balance.pop();
                generate(target, open, closed + 1, text, balance, response);
                balance.push(')');
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
