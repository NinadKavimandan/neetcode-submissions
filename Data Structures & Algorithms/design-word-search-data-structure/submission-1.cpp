class WordDictionary {
public:
    typedef struct Trie
    {
        vector<Trie*> next;
        bool wordEnd;

        Trie() : next(vector<Trie*>(26, nullptr)), wordEnd(false) {};
    } Trie;

    Trie* root;
    WordDictionary()
    {
        root = new Trie();
    }
    
    void addWord(string word)
    {
        Trie* iter = root;

        for (char c : word)
        {
            if (iter->next[c - 'a'] == nullptr)
            {
                iter->next[c - 'a'] = new Trie();;
            }

            iter = iter->next[c - 'a'];
        }

        iter->wordEnd = true;
    }
    
    bool search (Trie* iter, string word, int pos)
    {
        for (int i=pos;i < word.size();i++)
        {
            if (word[i] == '.')
            {
                for (Trie* child : iter->next)
                {
                    if (child != nullptr && search(child, word, i + 1))
                    {
                        return true;
                    }
                }

                return false;
            }
            else
            {
                if (iter->next[word[i] - 'a'] == nullptr)
                {
                    return false;
                }

                iter = iter->next[word[i] - 'a'];
            }
        }

        return iter->wordEnd;
    }

    bool search(string word)
    {
        Trie* iter = root;
        return search(iter, word, 0);
    }
};

/*

Trie to maintain words, backtracking to search when wildcard (.) is present. or just add an extra pointer for wildcard within the trie structure and which always contains all peer children? 

*/