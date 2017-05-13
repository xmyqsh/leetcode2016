class HeapNode {
      public:
        int key, val;
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
    void insert(int key) {
        if (index.count(key)) {
            heap[index[key]].val++;
            heapUp(index[key]);
            heapDown(index[key]);
            return;
        }
        if (++size == heap.size())
            heap.push_back(HeapNode());
        heap[size].key = key;
        heap[size].val = 1;
        index[key] = size;
        heapUp(size);
    }
    void remove(int key) {
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
        if (--heap[x].val == 0) {
            heapSwap(x, size);
            index.erase(heap[size].key);
            --size;
        }
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
    int characterReplacement(string s, int k) {
        if (s.size() < 2) return s.size();
        if (k + 1 >= s.size()) return s.size();
        Heap maxHeap(false);
        int result = 1, b = 0, e = 0;
        for (; e != s.size(); ++e) {
            while (!maxHeap.empty() && e - b - maxHeap.top().val > k)
                maxHeap.remove(s[b++]);
            result = max(result, e - b);
            maxHeap.insert(s[e]);
        }
        while (!maxHeap.empty() && e - b - maxHeap.top().val > k)
            maxHeap.remove(s[b++]);
        result = max(result, e - b);
        return result;
    }
};
