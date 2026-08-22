class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        priority_queue<int> maxHeap;
        vector<int> taskCountMap(26, 0);
        vector<char> taskSet(tasks.size()*(n == 0 ? 1 : n), '.');

        for (char task : tasks)
        {
            taskCountMap[task - 'A']++; 
        }
        
        for (int i=0;i < 26;i++)
        {
            if (taskCountMap[i] != 0)
            {
                maxHeap.push(taskCountMap[i]);
            }
        }

        int idles = (maxHeap.top() - 1)* n;
        int pocketSize = maxHeap.top() - 1;
        int total = maxHeap.top();
        maxHeap.pop();

        while (!maxHeap.empty())
        {
            idles -= min(maxHeap.top(), pocketSize);
            total += maxHeap.top();
            maxHeap.pop();
        }

        return total + max(0, idles);
    }
};

/*

lets think of a very basic solution first

count all unique jobs and their keep their counts

place each instance a unique job n tiles apart, for each next job, find vacant spots at n distance.

*/