class Solution {
public:
    bool isPalindrome(string& s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end])
            {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }

    void generate (string& s, int pos, vector<string>& temp, vector<vector<string>>& response)
    {
        if (pos == s.size())
        {
            response.push_back(temp);
        }
        else
        {
            int spos = pos;
            while (spos < s.size())
            {
                if (isPalindrome(s, pos, spos))
                {
                    temp.push_back(s.substr(pos, (spos - pos + 1)));
                    generate(s, spos + 1, temp, response);
                    temp.pop_back();
                }
                spos++;
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<string> temp;
        vector<vector<string>> response;
        generate(s, 0, temp, response);
        return response;
    }
};

/*

generate substrings, if they are palindrome, add them to the list and generate next substrings.

*/