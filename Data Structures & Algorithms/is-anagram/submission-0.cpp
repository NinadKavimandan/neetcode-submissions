class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        unordered_map<char, int> charCount;

        for (char c : s)
        {
            charCount[c]++;
        }

        for (char c : t)
        {
            charCount[c]--;
        }

        for (pair<char, int> tup : charCount)
        {
            if (tup.second != 0)
            {
                return false;
            }
        }

        return true;
    }
};
