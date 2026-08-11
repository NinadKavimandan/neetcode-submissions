class LRUCache {
public:
    typedef struct Node
    {
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
    } Node;

    int cacheCapacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* end;
    LRUCache(int capacity)
    {
        cacheCapacity = capacity;
        head = new Node(0, 0);
        end = new Node(0, 0);
        head->next = end;
        end->prev = head;
    }
    
    int get(int key)
    {
        auto valueNode = cache.find(key);
        if (valueNode == cache.end())
        {
            return -1;
        }

        cache[key]->prev->next = cache[key]->next;
        cache[key]->next->prev = cache[key]->prev;
        head->next->prev = cache[key];
        cache[key]->next = head->next;
        head->next = cache[key];
        cache[key]->prev = head;

        return cache[key]->value;
    }
    
    void put(int key, int value)
    {
        if (cache.find(key) == cache.end())
        {
            cache[key] = new Node(key, value);

            if (cache.size() > cacheCapacity)
            {
                int toRemove = end->prev->key;
                end->prev->prev->next = end;
                end->prev = end->prev->prev;
                delete cache[toRemove];
                cache.erase(toRemove);
            }
        }
        else
        {
            cache[key]->value = value;
            // remove from current position
            cache[key]->prev->next = cache[key]->next;
            cache[key]->next->prev = cache[key]->prev;
        }

        // add next to head
        head->next->prev = cache[key];
        cache[key]->next = head->next;
        head->next = cache[key];
        cache[key]->prev = head;
    }
};

/*

get and put both need to be O(1), O(1) lookup an be achieved with a map.
for the eviction part when cache goes out of capacity, we can use a doubly linked list, prev and next pointers. Use two padding nodes, head and end, head->next is most recent, end->prev is least recent. Store Node* in the map for quickly updating the pointers and evicting the least recently used number.

*/