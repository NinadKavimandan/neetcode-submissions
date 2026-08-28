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

    void generate (string& s, int spos, int pos, vector<string>& temp, vector<vector<string>>& response)
    {
        if (pos == s.size())
        {
            response.push_back(temp);
        }
        else
        {
            while (spos < s.size())
            {
                string substring = s.substr(pos, (spos - pos + 1));
                if (isPalindrome(s, pos, spos))
                {
                    temp.push_back(substring);
                    generate(s, spos + 1, spos + 1, temp, response);
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
        generate(s, 0, 0, temp, response);
        return response;
    }
};

/*

generate substrings, if they are palindrome, add them to the list.
the major problem is how to group them. 

*/