class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        normSk.push(x);
        if (minSk.empty()) minSk.push(x);
        else minSk.push(min(minSk.top(), x));
    }
    
    void pop() {
        normSk.pop();
        minSk.pop();
    }
    
    int top() {
        return normSk.top();
    }
    
    int getMin() {
        return minSk.top();
    }
private:
    stack<int> normSk;
    stack<int> minSk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
