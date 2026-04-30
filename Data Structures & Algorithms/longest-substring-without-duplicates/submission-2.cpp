class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if (s.size() < 2)
            return s.size();

        vector<bool> uniques(128);
        int left = 0;
        int right = 0;
        int maxLength = 0;

        while (right < s.size())
        {
            if (!uniques[s[right]])
            {
                uniques[s[right]] = true;
                right++;
                maxLength = max(maxLength, right - left);
            }
            else
            {
                while (left < right && uniques[s[right]])
                {
                    uniques[s[left]] = false;
                    left++;
                }
            }
        }

        return maxLength;
    }
};

/*

seems like a case for sliding window.
grow window to the right if allowed, shrink from left if duplicate next.
use unordered_set for quick lookups.

*/