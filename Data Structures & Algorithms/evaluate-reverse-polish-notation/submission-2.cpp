class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> tokensStacked;

        int first = 0;
        int second = 0;

        for (string token : tokens)
        {
            if (token.size() == 1)
            {
                switch (token[0])
                {
                    case '+':
                        first = tokensStacked.top();
                        tokensStacked.pop();

                        second = tokensStacked.top();
                        tokensStacked.pop();

                        tokensStacked.push(first + second);
                        break;
                    case '-':
                        first = tokensStacked.top();
                        tokensStacked.pop();

                        second = tokensStacked.top();
                        tokensStacked.pop();

                        tokensStacked.push(second - first);
                        break;
                    case '*':
                        first = tokensStacked.top();
                        tokensStacked.pop();

                        second = tokensStacked.top();
                        tokensStacked.pop();

                        tokensStacked.push(first * second);
                        break;
                    case '/':
                        first = tokensStacked.top();
                        tokensStacked.pop();

                        second = tokensStacked.top();
                        tokensStacked.pop();

                        tokensStacked.push(second / first);
                        break;
                    default:
                        tokensStacked.push(stoi(token));
                }
            }
            else
            {
                tokensStacked.push(stoi(token));
            }
        }

        return tokensStacked.top();
    }
};

/*

seem kinda straightforward tbh, let's see how it goes. push in operand, pop on encountering operator, push back the result.
finally, return top of the stack when its all over

*/