class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        unordered_map<char, int> taskCountMap;
        int maxFreq = 0;
        char maxFreqChar;
        for (char task : tasks)
        {
            taskCountMap[task]++;
            if (taskCountMap[task] > maxFreq)
            {
                maxFreq = taskCountMap[task];
                maxFreqChar = task;
            }
        }

        int gapSize = maxFreq - 1;
        int idles = gapSize* n;
        int total = maxFreq;

        for (auto& entry : taskCountMap)
        {
            if (entry.first != maxFreqChar)
            {
                idles -= min(entry.second, gapSize);
                total += entry.second;
            }
        }

        return total + max(0, idles);
    }
};

/*

lets think of a very basic solution first

count all unique jobs and their keep their counts

place each instance a unique job n tiles apart, for each next job, find vacant spots at n distance.

*/