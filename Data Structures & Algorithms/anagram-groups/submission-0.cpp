class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<int>> charCountStringMap;
        vector<vector<string>> response;

        for (int index=0;index<strs.size();index++)
        {
            string charCount = "00000000000000000000000000";
            for (char c : strs[index])
            {
                charCount[c - 'a']++;
            }

            charCountStringMap[charCount].push_back(index);
        }

        for (pair entry : charCountStringMap)
        {
            vector<string> tempSet;

            for (int index : entry.second)
            {
                tempSet.push_back(strs[index]);
            }

            response.push_back(tempSet);
        }

        return response;
    }
};


/*

tl;dr - group anagrams together

how do you identify anagrams? use char count map to see if two strings use same char count distribution.
how to go about this? we can have a map of string against count list, where string indicates the char count map. now does unordered_map allows string as key? we will know soon enough.

*/