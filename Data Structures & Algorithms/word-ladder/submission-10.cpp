class Solution {
public:
    int diff (string& first, string& second)
    {
        int count = 0;

        for (int i=0;i < first.size();i++)
        {
            if (first[i] != second[i])
            {
                count++;
            }
        }

        return count;
    }

    void buildAdjList (vector<string>& wordList, string beginWord, vector<vector<int>>& adjList)
    {
        for (int i=0;i < wordList.size();i++)
        {
            for (int j=i + 1;j < wordList.size();j++)
            {
                if (diff(wordList[i], wordList[j]) == 1)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
    }

    int find (vector<string>& wordList, string target)
    {
        for (int i=0;i < wordList.size();i++)
        {
            if (diff(wordList[i], target) == 0)
            {
                return i;
            }
        }

        return -1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        // check if end word even exists
        int endWordPos = find(wordList, endWord);
        if (endWordPos == -1)
        {
            return 0;
        }

        int beginPos = find(wordList, beginWord);
        int totalWords = wordList.size();
        if (beginPos == -1)
        {
            beginPos = wordList.size();
            wordList.push_back(beginWord);
            totalWords++;
        }

        vector<bool> visited(wordList.size(), false);
        vector<vector<int>> adjList(wordList.size(), vector<int>());
        int curDiff = diff(beginWord, endWord);
        int minChain = INT_MAX;

        // build the adj list
        buildAdjList(wordList, beginWord, adjList);
        
        queue<pair<int, int>> nodeQueue;
        nodeQueue.push({beginPos, 1});
        visited[beginPos] = true;
        while (!nodeQueue.empty())
        {
            pair<int, int>& node = nodeQueue.front();
            for (int& next : adjList[node.first])
            {
                if (next == endWordPos)
                {
                    minChain = min(minChain, node.second + 1);
                    continue;
                }

                if (!visited[next])
                {
                    visited[next] = true;
                    nodeQueue.push({next, node.second + 1});
                }
            }

            nodeQueue.pop();
        }

        return minChain == INT_MAX ? 0 : minChain;
    }
};

/*

build a list of neighbours, exactly 1 position apart for each word.
perform dfs from beginWord, till you explore all paths leading to endWord, return the smallest.
building the adj list itself is expensive here though, lets get a working version out first.

*/
