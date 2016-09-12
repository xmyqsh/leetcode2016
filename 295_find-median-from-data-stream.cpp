class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if (maxHeap.empty() || num > maxHeap.top()) minHeap.push(num);
        else maxHeap.push(num);
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) return (maxHeap.top() + minHeap.top()) / (double)(2.0);
        else return maxHeap.top();
    }
private:
    priority_queue<int, vector<int>, less<int> > maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
