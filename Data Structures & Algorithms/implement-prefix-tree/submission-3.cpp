class PrefixTree {
public:
    typedef struct Trie
    {
        vector<Trie*> next;
        bool wordEnd;

        Trie() : next(vector<Trie*>(26, nullptr)), wordEnd(false) {}
    } Trie;

    Trie* root;

    PrefixTree()
    {
        root = new Trie();
    }
    
    void insert(string word)
    {
        Trie* iter = root;
        for (char c : word)
        {
            if (iter->next[c - 'a'] == nullptr)
            {
                iter->next[c - 'a'] = new Trie();
            }
            iter = iter->next[c - 'a'];
        }

        iter->wordEnd = true;
    }
    
    bool search(string word)
    {
        Trie* iter = root;

        for (char c : word)
        {
            if (iter->next[c - 'a'] == nullptr)
            {
                return false;
            }

            iter = iter->next[c - 'a'];
        }

        return iter->wordEnd;
    }
    
    bool startsWith(string prefix)
    {
        Trie* iter = root;

        for (char c : prefix)
        {
            if (iter->next[c - 'a'] == nullptr)
            {
                return false;
            }

            iter = iter->next[c - 'a'];
        }

        return true;
    }
};

/*

create a trie with a structure containing the character, 26 pointers for each character, and a flag to suggest if its the end of a word.

*/