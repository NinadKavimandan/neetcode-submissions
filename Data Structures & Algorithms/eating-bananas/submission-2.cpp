class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int maxBananas = INT_MIN;

        for (int pile : piles)
        {
            maxBananas = max(maxBananas, pile);
        }

        int left = 1;
        int right = maxBananas;
        int mid = (left + right) / 2;
        int minB = right;
        while (left <= right)
        {
            int totalHours = 0;
            for (int pile : piles)
            {
                totalHours += ceil((double)pile/mid);
            }

            if (totalHours <= h)
            {
                minB = min(minB, mid);
                right = mid - 1;
            }
            else if (totalHours > h)
            {
                left = mid + 1;
            }

            mid = left + (right - left)/2;
        }

        return minB;
    }
};

/*

this feels like binary search, except you look for k within a range of (smallest pile size, largest size pile)

left = minBananas
right = maxBananas

mid = (minBananas + maxBananas)/2 becomes the midpoint against which we check,

if number of hours with mid > h
    left = mid
else if mid < h
    right = mid

keep on doing this while left < right
finally return left or mid?
*/