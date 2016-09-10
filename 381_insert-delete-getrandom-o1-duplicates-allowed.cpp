class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        dict[val].insert(nums.size());
        nums.push_back(val);
        return dict[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (!dict.count(val)) return false;
        int last = nums.back();
        int pos = *(dict[val].rbegin());
        nums[pos] = last;
        nums.pop_back();
        dict[last].erase(*(dict[last].rbegin()));
        dict[last].insert(pos);
        if (dict[val].size() > 1) dict[val].erase(*(dict[val].rbegin()));
        else dict.erase(val);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;
    unordered_map<int, set<int> > dict;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
