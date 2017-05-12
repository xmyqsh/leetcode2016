class HeapNode {
      public:
        int key, val;
        HeapNode() {}
        HeapNode(int k, int v) : key(k), val(v) {}
        HeapNode(const HeapNode& rh) {
            this->key = rh.key;
            this->val = rh.val;
        }
};

class Heap {
public:
    Heap(bool type) {
        this->heap.resize(1);
        this->size = 0;
        this->type = type;
    }
    int sIze() const {
        return this->size;
    }
    bool empty() const {
        return this->size == 0;
    }
    void insert(const HeapNode& hn) {
        if (++size == heap.size())
            heap.push_back(HeapNode());
        heap[size].key = hn.key;
        heap[size].val = hn.val;
        index[hn.key] = size;
        heapUp(size);
    }
    void remove(int key) {
        if (index.count(key))
            del(index[key]);
    }
    HeapNode top() const {
        return heap[1];
    }
    void pop() {
        del(1);
    }
private:
    void heapSwap(int x, int y) {
        swap(heap[x], heap[y]);
        index[heap[x].key] = x;
        index[heap[y].key] = y;
    }
    void heapUp(int x) {
        while (x != 1 && (type ? heap[x / 2].val > heap[x].val : heap[x / 2].val < heap[x].val)) {
            heapSwap(x / 2, x);
            x /= 2;
        }
    }
    void heapDown(int x) {
        while (x <= size / 2) {
            int tmp = 2 * x;
            if (tmp + 1 <= size && (type ? heap[tmp + 1].val < heap[tmp].val : heap[tmp + 1].val > heap[tmp].val))
                ++tmp;
            if (type ? heap[x].val > heap[tmp].val : heap[x].val < heap[tmp].val) {
                heapSwap(x, tmp);
                x = tmp;
            } else break;
        }
    }
    void del(int x) {
        heapSwap(x, size);
        index.erase(heap[size].key);
        --size;
        heapUp(x);
        heapDown(x);
    }
private:
    vector<HeapNode> heap;
    unordered_map<int, int> index;
    int size;
    bool type; // minHeap: type = 1, maxHeap = 0
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        if (k == 0 || nums.size() < k) return result;
        Heap minHeap(true), maxHeap(false);
        int i = 0;
        for (; i != k; ++i) {
            if (maxHeap.empty() || nums[i] > maxHeap.top().val) minHeap.insert(HeapNode(i, nums[i]));
            else maxHeap.insert(HeapNode(i, nums[i]));
            if (maxHeap.sIze() < minHeap.sIze()) {
                maxHeap.insert(minHeap.top());
                minHeap.pop();
            } else if (maxHeap.sIze() > minHeap.sIze() + 1) {
                minHeap.insert(maxHeap.top());
                maxHeap.pop();
            }
        }
        for (; i != nums.size(); ++i) {
            if (k & 1) result.push_back(maxHeap.top().val);
            else result.push_back(((double)maxHeap.top().val + minHeap.top().val) / 2.0);
            maxHeap.remove(i - k); minHeap.remove(i - k);
            if (maxHeap.empty() || nums[i] > maxHeap.top().val) minHeap.insert(HeapNode(i, nums[i]));
            else maxHeap.insert(HeapNode(i, nums[i]));
            if (maxHeap.sIze() < minHeap.sIze()) {
                maxHeap.insert(minHeap.top());
                minHeap.pop();
            } else if (maxHeap.sIze() > minHeap.sIze() + 1) {
                minHeap.insert(maxHeap.top());
                maxHeap.pop();
            }
        }
        if (k & 1) result.push_back(maxHeap.top().val);
        else result.push_back(((double)maxHeap.top().val + minHeap.top().val) / 2.0);
        return result;
    }
};
