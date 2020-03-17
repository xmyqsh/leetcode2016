// O(Ok) = O(40000*40000)
// TODO: Optimize this
class ProductOfNumbers {
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        arr.push_back(num);
    }
    
    int getProduct(int k) {
        int ret = 1;
        for (int i = arr.size() - 1, j = 0; j != k; ++j, --i) {
            ret *= arr[i];
        }
        return ret;
    }
private:
    vector<int> arr;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
