class Solution {
public:
    vector<string> digitLetterMap = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    void generate (const string& digits, int start, string& temp, vector<string>& response)
    {
        if (start == digits.size())
        {
            response.push_back(temp);
            return;
        }

        for (char letter : digitLetterMap[digits[start] - '2'])
        {
            temp.push_back(letter);
            generate(digits, start + 1, temp, response);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            return {};
        }

        string temp;
        vector<string> response;
        generate (digits, 0, temp, response);

        return response;
    }
};

/*

use backtracking, add each possible letter for the number and recurse with that path forward. if you are at the end of the digits, add that to the response.

*/