class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if (s.size() < 2)
            return s.size();

        unordered_set<char> uniques;
        int left = 0;
        int right = 0;

        int curLength = 0;
        int maxLength = 0;

        while (right < s.size())
        {
            if (uniques.find(s[right]) == uniques.end())
            {
                uniques.insert(s[right]);
                right++;
                curLength++;
                maxLength = max(maxLength, curLength);
            }
            else
            {
                while (left < right && uniques.find(s[right]) != uniques.end())
                {
                    uniques.erase(s[left]);
                    left++;
                    curLength--;
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