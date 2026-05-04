class Solution {
public:
    bool isOpeningBracket(char c)
    {
        switch(c)
        {
            case '(':
            case '[':
            case '{':
                return true;
            default:
                return false;
        }
        return false;
    }

    char getClosingBracket(char c)
    {
        switch(c)
        {
            case '(':
                return ')';
            case '[':
                return ']';
            case '{':
                return '}';
        }
        return 'X'; // dummy, this would never happen as stack top is always an opening bracket.
    }

    bool isValid(string s)
    {
        stack<char> brackets;
        for (char c : s)
        {
            if (isOpeningBracket(c))
            {
                brackets.push(c);
            }
            else
            {
                if (!brackets.empty() && getClosingBracket(brackets.top()) == c)
                {
                    brackets.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        return brackets.empty();
    }
};

/*

look for every closing bracket for every opening one.
immediate thing that comes to mind is a two pointer method, one on the left, one on the right, but that works only for strictly symmetrical parentheses strings.
instead, we can store each opening paranthese in a stack, pop out only after encountering corresponding closing bracket.

why stack works? parenthese close in the reverse order of opening, the opening bracket you encounter first in a nested string would likely close later than the ones you encounter within.

*/