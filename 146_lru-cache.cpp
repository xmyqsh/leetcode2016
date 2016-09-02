class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        auto iter = cacheMap.find(key);
        if (iter == cacheMap.end()) return -1;
        cacheList.push_front(*iter->second);
        cacheList.erase(iter->second);
        iter->second = cacheList.begin();
        return iter->second->second;
    }

    void set(int key, int value) {
        auto iter = cacheMap.find(key);
        if (iter == cacheMap.end()) {
            while (cacheMap.size() >= capacity) {
                cacheMap.erase(cacheList.crbegin()->first);
                cacheList.pop_back();
            }
        } else {
            cacheList.erase(iter->second);
        }
        cacheList.push_front(make_pair(key, value));
        cacheMap[key] = cacheList.begin();
    }
private:
    list<pair<int, int> > cacheList;
    unordered_map<int, list<pair<int, int> >::iterator> cacheMap;
    int capacity;
};
