class Solution {
public:
    void generate (int target, int open, int closed, string& text, vector<string>& response)
    {
        if (text.size() == 2*target)
        {
            stack<char> balance;
            for (char c : text)
            {
                if (c == '(')
                {
                    balance.push(c);
                }
                else if (c == ')')
                {
                    if (balance.empty())
                    {
                        balance.push(c);
                        break;
                    }

                    balance.pop();
                }
            }

            if (balance.empty())
            {
                response.push_back(text);
            }
        }
        else
        {
            // for (int i=open;i < target;i++)
            // {
            //     text += '(';
            //     cout<<"add open "<<text<<endl;
            //     int newSize = text.size() - 1;
            //     generate(target, open + 1, closed, text, response);
            //     text.erase(newSize, 1);
            // }

            if (open < target)
            {
                text += '(';
                int newSize = text.size() - 1;
                generate(target, open + 1, closed, text, response);
                text.erase(newSize, 1);
            }

            // for (int i=closed;i < target;i++)
            // {
            //     text += ')';
            //     cout<<"add closed "<<text<<endl;
            //     int newSize = text.size() - 1;
            //     generate(target, open, closed + 1, text, response);
            //     text.erase(newSize, 1);
            // }

            if (closed < target)
            {
                text += ')';
                int newSize = text.size() - 1;
                generate(target, open, closed + 1, text, response);
                text.erase(newSize, 1);
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
