class Solution {
public:
    void generate (const string& digits, unordered_map<char, vector<char>>& digitLetterMap, int start, string& temp, vector<string>& response)
    {
        if (start == digits.size())
        {
            response.push_back(temp);
        }

        for (char letter : digitLetterMap[digits[start]])
        {
            temp.push_back(letter);
            generate(digits, digitLetterMap, start + 1, temp, response);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            return {};
        }
        
        unordered_map<char, vector<char>> digitLetterMap;
        digitLetterMap['2'] = {'a', 'b', 'c'};
        digitLetterMap['3'] = {'d', 'e', 'f'};
        digitLetterMap['4'] = {'g', 'h', 'i'};
        digitLetterMap['5'] = {'j', 'k', 'l'};
        digitLetterMap['6'] = {'m', 'n', 'o'};
        digitLetterMap['7'] = {'p', 'q', 'r', 's'};
        digitLetterMap['8'] = {'t', 'u', 'v'};
        digitLetterMap['9'] = {'w', 'x', 'y', 'z'};

        string temp;
        vector<string> response;
        generate (digits, digitLetterMap, 0, temp, response);

        return response;
    }
};

/*

use backtracking, add each possible letter for the number and recurse with that path forward. if you are at the end of the digits, add that to the response.

*/