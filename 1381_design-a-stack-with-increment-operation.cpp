class CustomStack {
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        this->memo.resize(maxSize);
        this->topIdx = 0;
    }
    
    void push(int x) {
        if (topIdx == maxSize) return;
        memo[topIdx++] = x;
    }
    
    int pop() {
        if (topIdx == 0) return -1;
        return memo[--topIdx];
    }
    
    void increment(int k, int val) {
        for (int i = 0; i != min(k, topIdx); ++i) {
            memo[i] += val;
        }
    }
private:
    vector<int> memo;
    int maxSize, topIdx;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
