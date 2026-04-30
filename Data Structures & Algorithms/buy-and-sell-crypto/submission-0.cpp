class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int low = INT_MAX;
        int profit = 0;
        for (int price : prices)
        {
            if (price < low)
            {
                low = price;
            }
            else
            {
                profit = max(profit, (price - low));
            }
        }

        return profit;
    }
};

/*

basically, look for the largest difference from left to right.
we want to maximize the profit, we can use two pointers, one going forward, one going reverse.
start at left, end at right.
if end is less than start, no sale, move end to the left.
if start is less than end- won't work, if first element is the biggest one, you will just starve.

instead of this, we can use a monotonic stack to keep track of elements.
push lesser element on the top, if current element is higher, compute the difference, see if its greater than what you seen so far.

*/