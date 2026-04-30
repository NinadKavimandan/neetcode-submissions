class Solution {
public:
    bool isValid(char c)
    {
        return isalpha(c) || isdigit(c);
    }

    bool areEqual(char first, char second)
    {
        return tolower(first) == tolower(second);
    }

    bool isPalindrome(string s) 
    {
        int start = 0;
        int end = s.size() - 1;

        while (start < end)
        {
            while (start < s.size() && !isValid(s[start]))
            {
                start++;
            }

            while (end > -1 && !isValid(s[end]))
            {
                end--;
            }

            if (!areEqual(s[start], s[end]))
            {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
};

/*

two pointers may be, skip special characters and symbols. increment both at the same time

*/