class Solution {
public:
    void buildAdjList (vector<string>& wordList, string beginWord, vector<vector<int>>& adjList)
    {
        for (int i=0;i < wordList.size();i++)
        {
            for (int j=i + 1;j < wordList.size();j++)
            {
                int diff = 0;
                for (int c=0;c < wordList[0].size();c++)
                {
                    if (wordList[i][c] != wordList[j][c])
                    {
                        diff++;

                        if (diff > 1)
                        {
                            break;
                        }
                    }
                }

                if (diff == 1)
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
            int matched = 0;
            for (int j=0;j < target.size();j++)
            {
                if (wordList[i][j] == target[j])
                {
                    matched++;
                }
            }

            if (matched == target.size())
            {
                return i;
            }
        }

        return -1;
    }

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

    void dfs (vector<string>& wordList, vector<vector<int>>& adjList, int start, int end, int curChain, int& minChain, int& curDiff, vector<bool>& visited)
    {
        if (start == end)
        {
            minChain = min(minChain, curChain);
            return;
        }

        if (curChain == minChain)
        {
            return;
        }

        visited[start] = true;
        for (int next : adjList[start])
        {
            int newDiff = diff(wordList[next], wordList[end]);
            if (!visited[next] && newDiff <= curDiff)
            {
                dfs(wordList, adjList, next, end, curChain + 1, minChain, newDiff, visited);
                visited[next] = false;
            }
        }
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
            cout<<wordList[node.first]<<endl;
            for (int& next : adjList[node.first])
            {
                cout<<" looking "<<endl;
                if (next == endWordPos)
                {
                    cout<<"found"<<endl;
                    minChain = min(minChain, node.second + 1);
                    cout<<"at "<<minChain<<endl;
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
