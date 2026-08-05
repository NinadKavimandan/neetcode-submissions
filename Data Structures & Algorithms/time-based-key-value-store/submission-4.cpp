class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> metaMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp)
    {
        if (metaMap.find(key) == metaMap.end())
        {
            metaMap[key] = {{timestamp, value}};
        }
        else
        {
            metaMap[key].push_back({timestamp, value});
        }
    }
    
    string get(string key, int timestamp)
    {
        if (metaMap.find(key) == metaMap.end())
        {
            return "";
        }

        const vector<pair<int, string>>& timestamps = metaMap[key];
        int start = 0;
        int total = timestamps.size();
        int end = total;

        if (timestamps[0].first > timestamp)
        {
            return "";
        }
        while (start < end)
        {
            int mid = start + (end - start)/2;
            if (timestamps[mid].first == timestamp)
            {
                return timestamps[mid].second;
            }

            if (timestamps[mid].first > timestamp)
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }

        return timestamps[start - 1].second;
    }
};

/*
use unordered_map for storing keys and faster retrieval
use value as a vector of objects/pair -> (timestamp, value)
since timestamp is guaranteed to be increasing, we can use binary serach to narrow down on either the exact or closest value to the timestamp for the key.
*/