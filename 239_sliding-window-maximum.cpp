class Heap {
public:
    Heap(bool type) {
        this->heap.resize(1);
        this->size = 0;
        this->type = type;
    }

    void insert(int key, int val) {
        if (++size == heap.size())
            heap.push_back(HeapNode());
        heap[size].key = key;
        heap[size].val = val;
        index[key] = size;
        heapUp(size);
    }
    void remove(int key) {
        del(index[key]);
    }
    int top() const {
        return heap[1].val;
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
    struct HeapNode {
        int key, val;
    };
private:
    vector<HeapNode> heap;
    unordered_map<int, int> index;
    int size;
    bool type; // minHeap: type = 1, maxHeap = 0
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if (k == 0 || nums.size() < k) return result;
        Heap maxHeap(false);
        int i = 0;
        for (; i != k; ++i)
            maxHeap.insert(i, nums[i]);
        for (; i != nums.size(); ++i) {
            result.push_back(maxHeap.top());
            maxHeap.remove(i - k);
            maxHeap.insert(i, nums[i]);
        }
        result.push_back(maxHeap.top());
        return result;
    }
};
