class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        sk1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        convert();
        sk2.pop();
    }

    // Get the front element.
    int peek(void) {
        convert();
        return sk2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return sk1.empty() && sk2.empty();
    }
private:
    void convert() {
        if (sk2.empty()) {
            while (!sk1.empty()) {
                sk2.push(sk1.top());
                sk1.pop();
            }
        }
    }
    stack<int> sk1, sk2;
};
