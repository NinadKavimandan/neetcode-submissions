class MinStack {
public:
    stack<vector<int>> numStack;
    int curMin = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if (val < curMin)
        {
            curMin = val;
        }

        numStack.push({val, curMin});
    }
    
    void pop() {
        int top = numStack.top()[0];
        numStack.pop();

        if (curMin == top)
        {
            if (numStack.empty())
            {
                curMin = INT_MAX;
            }
            else
            {
                curMin = numStack.top()[1];
            }
        }
    }
    
    int top() {
        return numStack.top()[0];
    }
    
    int getMin() {
        return numStack.top()[1];
    }
};

/*

now this is interesting, on one hand, push, pop, and top on a stack is already O(1)
getMin is the real deal. pre-computing this value is what makes this function do O(1)
we can use a min heap to maintain the rolling minimum, return top of heap on each getMin query.
only remove values from the heap if the pop on the stack is the current min, in which case, keep on popping till the new min is not already removed - this would involve maintaining too much data.
we could instead use a monotonic deque, but that would need a lot of seeking out the popped elements eventually, might as well try heap first.

*/