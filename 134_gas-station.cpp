class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int remain = 0, cur = 0, idx = -1;
        for (int i = 0; i < gas.size(); ++i) {
            int tmp = gas[i] - cost[i];
            remain += tmp;
            cur += tmp;
            if (cur < 0) {
                cur = 0;
                idx = i;
            }
        }
        return remain >= 0 ? idx + 1 : -1;
    }
};
