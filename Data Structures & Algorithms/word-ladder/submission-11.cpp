class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        // base case, when endWord is absent from the word list
        unordered_map<string, int> wordIndexMap;
        for (int i=0;i < wordList.size();i++)
        {
            wordIndexMap[wordList[i]] = i;
        }

        if (!wordIndexMap.contains(endWord))
        {
            return 0;
        }

        // build adjlist for traversal
        if (!wordIndexMap.contains(beginWord))
        {
            wordIndexMap[beginWord] = wordList.size();
            wordList.push_back(beginWord);
        }
        vector<vector<int>> adjList(wordList.size(), vector<int>());

        for (int i=0;i < wordList.size();i++)
        {
            for (int j=0;j < beginWord.size();j++)
            {
                string curWord = wordList[i];
                for (int c=0;c < 26;c++)
                {
                    curWord[j] = c + 'a';
                    auto pos = wordIndexMap.find(curWord);
                    if (pos != wordIndexMap.end() && pos->second != i)
                    {
                        adjList[i].push_back(pos->second);
                        adjList[pos->second].push_back(i);
                    }
                }
            }
        }

        vector<bool> visited(wordList.size());
        queue<pair<int, int>> wordQueue;
        int end = wordIndexMap[endWord];
        wordQueue.push({wordIndexMap[beginWord], 1});

        while (!wordQueue.empty())
        {
            pair<int, int>& word = wordQueue.front();
            visited[word.first] = true;

            for (int next : adjList[word.first])
            {
                if (next == end)
                {
                    return word.second + 1;
                }
                else
                {
                    if (!visited[next])
                    {
                        wordQueue.push({next, word.second + 1});
                    }
                }
            }

            wordQueue.pop();
        }

        return 0;
    }
};
