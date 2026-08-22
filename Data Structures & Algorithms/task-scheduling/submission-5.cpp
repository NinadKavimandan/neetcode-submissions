class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        priority_queue<int> maxHeap;
        unordered_map<char, int> taskCountMap;

        for (char task : tasks)
        {
            taskCountMap[task]++; 
        }
        
        for (auto& entry : taskCountMap)
        {
            maxHeap.push(entry.second);
        }

        int maxFreq = maxHeap.top();
        int pocketSize = maxFreq - 1;
        int idles = pocketSize* n;
        int total = maxFreq;
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