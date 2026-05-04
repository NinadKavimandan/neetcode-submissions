class MinStack {
public:
    stack<int> numStack;
    priority_queue<int, vector<int>, greater<int>> rollingMin;
    unordered_map<int, int> poppedCounter;
    MinStack() {
        
    }
    
    void push(int val) {
        numStack.push(val);

        rollingMin.push(val);
    }
    
    void pop() {
        int top = numStack.top();
        numStack.pop();

        poppedCounter[top]++;

        while (poppedCounter[rollingMin.top()] != 0)
        {
            poppedCounter[rollingMin.top()]--;
            rollingMin.pop();
        }
    }
    
    int top() {
        return numStack.top();
    }
    
    int getMin() {
        return rollingMin.top();
    }
};

/*

now this is interesting, on one hand, push, pop, and top on a stack is already O(1)
getMin is the real deal. pre-computing this value is what makes this function do O(1)
we can use a min heap to maintain the rolling minimum, return top of heap on each getMin query.
only remove values from the heap if the pop on the stack is the current min, in which case, keep on popping till the new min is not already removed - this would involve maintaining too much data.
we could instead use a monotonic deque, but that would need a lot of seeking out the popped elements eventually, might as well try heap first.

*/