class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        stack<int> tempStack;
        vector<int> response(temperatures.size(), 0);

        for (int index = 0;index<temperatures.size();index++)
        {
            while (!tempStack.empty() && temperatures[index] > temperatures[tempStack.top()])
            {
                int curIndex = tempStack.top();
                response[curIndex] = index - curIndex;
                tempStack.pop();
            }

            tempStack.push(index);
        }

        return response;
    }
};

/*

umm may be use a monotonic stack, store indices in the stack.
keep on pushing to the stack if the temperature is lower than top of stack
if current temperature is greater, keep on popping the top till you either end up with higher top, or the stack is empty.

*/