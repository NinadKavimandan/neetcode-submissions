class Solution {
public:
    bool match(vector<int>& baseline, vector<int>& target)
    {
        for (int index=0;index<128;index++)
        {
            if (baseline[index] != 0 && target[index] < baseline[index])
            {
                return false;
            }
        }

        return true;
    }

    string minWindow(string s, string t)
    {
        if (s.size() < t.size())
        {
            return "";
        }

        vector<int> baselineMap(128, 0);
        vector<int> targetMap(128, 0);
        for (char c : t)
        {
            baselineMap[c]++;
        }

        int bestLength = INT_MAX;
        int bestStart = -1;
        int left = 0;
        int right = 0;

        while (right < s.size())
        {
            while (right < s.size() && !match(baselineMap, targetMap))
            {
                targetMap[s[right]]++;
                right++;
            }
            
            while (left < right && match(baselineMap, targetMap))
            {
                if (bestLength > right - left)
                {
                    bestLength = right - left;
                    bestStart = left;
                }

                targetMap[s[left]]--;
                left++;
            }
        }

        return bestStart != -1 ? s.substr(bestStart, bestLength) : "";
    }
};

/*

get the character freq map for t, compute that for s.
freq map for s must contain all characters from t, otherwise just return false.
we can use two pointers, start and end.
we start with entire s string length, and keep on reducing from a side, till s and t char maps do not match.
if they do not at any point, restore from that side, unrestore from the other side.
shrinking can be done from either side, and each decision may pop up with its own minimum string, we can just let it run in both directions and take whatever is shorter each time.
fuzzy logic, lets see how this holds up.

s = "OUZODYXAZV", t = "XYZ"

OUZODYXAZV
OUZODYXAZ
UZODYXAZ
ZODYXA or ODYXAZ
ZODYX or DYXAZ
ZODYX or YXAZ

hmm this is too complex and needs unnecessary branching.

simpler logic would be to start at start, grow towards right till all characters from t are present in substring of s.
shrink from left till all characters from t are no longer present in the substring of s.

*/