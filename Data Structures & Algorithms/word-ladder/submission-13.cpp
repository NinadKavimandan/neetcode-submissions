class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        // base case, when endWord is absent from the word list
        unordered_map<string, bool> wordVisitedMap;
        for (int i=0;i < wordList.size();i++)
        {
            wordVisitedMap[wordList[i]] = false;
        }

        if (!wordVisitedMap.contains(endWord))
        {
            return 0;
        }

        // build adjlist for traversal
        if (!wordVisitedMap.contains(beginWord))
        {
            wordVisitedMap[beginWord] = false;
            wordList.push_back(beginWord);
        }

        queue<pair<string, int>> wordQueue;
        wordQueue.push({beginWord, 1});

        while (!wordQueue.empty())
        {
            pair<string, int>& word = wordQueue.front();
            wordVisitedMap[word.first] = true;

            for (int j=0;j < word.first.size();j++)
            {
                string curWord = word.first;
                for (int c=0;c < 26;c++)
                {
                    curWord[j] = c + 'a';
                    if (curWord == endWord)
                    {
                        return word.second + 1;
                    }

                    if (curWord != word.first && wordVisitedMap.contains(curWord))
                    {
                        if (!wordVisitedMap[curWord])
                        {
                            wordVisitedMap[curWord] = true;
                            wordQueue.push({curWord, word.second + 1});
                        }
                    }
                }
            }

            wordQueue.pop();
        }

        return 0;
    }
};
