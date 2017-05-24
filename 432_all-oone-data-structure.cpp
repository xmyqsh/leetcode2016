class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (!key2bucketsIter.count(key))
            key2bucketsIter[key] = buckets.insert(buckets.begin(), {0, {key}});
        auto next = key2bucketsIter[key], bucket = next++;
        if (next == buckets.end() || next->value > bucket->value + 1)
            next = buckets.insert(next, {bucket->value + 1, {}});
        next->keys.insert(key);
        key2bucketsIter[key] = next;
        bucket->keys.erase(key);
        if (bucket->keys.empty())
            buckets.erase(bucket);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (!key2bucketsIter.count(key)) return;
        auto prev = key2bucketsIter[key], bucket = prev--;
        key2bucketsIter.erase(key);
        if (bucket->value > 1) {
            if (bucket == buckets.begin() || prev->value < bucket->value - 1)
                prev = buckets.insert(bucket, {bucket->value - 1, {}});
            prev->keys.insert(key);
            key2bucketsIter[key] = prev;
        }
        bucket->keys.erase(key);
        if (bucket->keys.empty())
            buckets.erase(bucket);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return buckets.empty() ? "" : *(buckets.begin()->keys.begin());
    }
private:
    struct Bucket { int value; unordered_set<string> keys; };
    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> key2bucketsIter;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
