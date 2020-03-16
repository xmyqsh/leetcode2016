class Cashier {
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n = n;
        this->cnt = 0;
        this->discount = discount;
        for (int i = 0; i != products.size(); ++i) id2p[products[i]] = prices[i];
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double ret = 0;
        ++cnt;
        for (int i = 0; i != product.size(); ++i) {
            ret += id2p[product[i]] * amount[i];
        }
        if (cnt == n) {
            cnt = 0;
            ret -= (discount * ret) / 100;
        }
        return ret;
    }
private:
    int n, cnt;
    double discount;
    unordered_map<int, int> id2p;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
