class MinStack {
public:
    stack<pair<int, int>> numStack;
    MinStack() {
        
    }
    
    void push(int val) {
        int curMin = numStack.empty() ? val : min(val, numStack.top().second);
        numStack.push({val, curMin});
    }
    
    void pop() {
        numStack.pop();
    }
    
    int top() {
        return numStack.top().first;
    }
    
    int getMin() {
        return numStack.top().second;
    }
};

/*

now this is interesting, on one hand, push, pop, and top on a stack is already O(1)
getMin is the real deal. pre-computing this value is what makes this function do O(1)
we can use a min heap to maintain the rolling minimum, return top of heap on each getMin query.
only remove values from the heap if the pop on the stack is the current min, in which case, keep on popping till the new min is not already removed - this would involve maintaining too much data.
we could instead use a monotonic deque, but that would need a lot of seeking out the popped elements eventually, might as well try heap first.

or - or - we just use the stack to maintain the minimum when new element was pushed

*/