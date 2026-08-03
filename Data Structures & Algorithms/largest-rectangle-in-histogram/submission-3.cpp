class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        stack<int> larger;
        unordered_map<int, int> startedAt;
        int maxArea = INT_MIN;
        int total = heights.size();

        for (int index = 0;index<total;index++)
        {
            int start = index;
            while (!larger.empty() && heights[larger.top()] > heights[index])
            {
                maxArea = max(maxArea, heights[larger.top()]*(index - startedAt[larger.top()]));
                start = startedAt[larger.top()];
                larger.pop();
            }

            larger.push(index);
            startedAt[index] = start;
        }

        while (!larger.empty())
        {
            maxArea = max(maxArea, heights[larger.top()]*(total - startedAt[larger.top()]));
            larger.pop();
        }

        return maxArea;
    }
};

/*

area of rectangle for (heights[i], heights[j]) => min(heights[i], heights[j])*(|i-j|)
you can just check every pair and eventually land on the answer, but that's the long road.

we basically need the position of the next highest element after the lower elements to identify a candidate rectangle, as all smaller ones would be smaller.
we can do a pass in O(n) from right to left first to identify non-decreasing sequence, maintaining the index of the element (or/and the value, but value is fetchable so its fine to use just the index too)

store this into a stack, and then traverse left to right, while comparing against the stack top.
if stack top index < current index, pop it off as it the largest rectangle from left must have been identified already
if stack top index == current, pop, but keep the area in count and compare against current max
if stack top index > current, compute the area and compare against the current max

*/