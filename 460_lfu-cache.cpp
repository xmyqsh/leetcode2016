class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!key2valFreq.count(key)) return -1;
        freq2listKey[key2valFreq[key].second].erase(key2listIter[key]);
        ++key2valFreq[key].second;
        freq2listKey[key2valFreq[key].second].push_back(key);
        key2listIter[key] = prev(freq2listKey[key2valFreq[key].second].end());
        if (freq2listKey[minFreq].size() == 0) ++minFreq;
        return key2valFreq[key].first;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        if (get(key) != -1) {
            key2valFreq[key].first = value;
            return;
        }
        if (key2valFreq.size() == capacity) {
            int key = freq2listKey[minFreq].front();
            freq2listKey[minFreq].pop_front();
            key2valFreq.erase(key);
            key2listIter.erase(key);
        }
        minFreq = 1;
        key2valFreq[key] = {value, minFreq};
        freq2listKey[minFreq].push_back(key);
        key2listIter[key] = prev(freq2listKey[minFreq].end());
    }
private:
    int capacity;
    int minFreq;
    unordered_map<int, pair<int, int> > key2valFreq;
    unordered_map<int, list<int>::iterator> key2listIter;
    unordered_map<int, list<int> > freq2listKey;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
