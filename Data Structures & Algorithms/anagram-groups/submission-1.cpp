class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> charCountStringMap;
        vector<vector<string>> response;

        for (string str : strs)
        {
            string charCount = "00000000000000000000000000";
            for (char c : str)
            {
                charCount[c - 'a']++;
            }

            charCountStringMap[charCount].push_back(str);
        }

        for (auto& entry : charCountStringMap)
        {
            response.push_back(entry.second);
        }

        return response;
    }
};


/*

tl;dr - group anagrams together

how do you identify anagrams? use char count map to see if two strings use same char count distribution.
how to go about this? we can have a map of string against count list, where string indicates the char count map. now does unordered_map allows string as key? we will know soon enough.

*/