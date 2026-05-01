class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> charFreqMap(26, 0);

        for (char c : s1)
        {
            charFreqMap[c - 'a']++;
        }

        int left = 0;
        int right = 0;
        vector<int> curCharMap(26, 0);

        while (right < s1.size())
        {
            curCharMap[s2[right] - 'a']++;
            right++;
        }

        while (right <= s2.size())
        {
            bool matched = true;
            for (int index=0;index<26;index++)
            {
                if (curCharMap[index] != charFreqMap[index])
                {
                    matched = false;
                }
            }

            if (matched)
            {
                return true;
            }

            curCharMap[s2[left] - 'a']--;
            left++;
            curCharMap[s2[right] - 'a']++;
            right++;
        }

        return false;
    }
};

/*

look for a window that starts with any element from s1.
we can maintain a frequencyMap for s1 using an array of 26 elements, then traverse s1.
if current character has presence in the frequency map, expand window to the right, whilst verifying if each forthcoming element adhers to the count and presence constraints from s1.

*/