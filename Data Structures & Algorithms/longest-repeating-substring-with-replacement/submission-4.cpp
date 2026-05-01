class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int response = 0;
        vector<int> uniques(26, 0);
        int left = 0;
        int count = 0;
        int maxFreq = 0;

        for (int right=0;right<s.size();right++)
        {
            uniques[s[right] - 'A']++;
            maxFreq = max(maxFreq, uniques[s[right] - 'A']);

            while ((right - left + 1) - maxFreq > k)
            {
                uniques[s[left] - 'A']--;
                left++;
            }

            response = max(response, (right - left + 1));
        }

        return response;
    }
};

/*

we essentially want longest sequence of repeating characters, with a tolerance of k.
we can probably use a sliding window with a variable to track the current character
grow the window if character matches or within tolerance,
shrink the window if out of tolerance.

hmm, may be choose character with highest count as a starter?

*/