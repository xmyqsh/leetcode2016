class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int ret = 0;
        vector<int> state(light.size() + 1, 0); state[0] = -1;
        for (int i = 0; i != light.size(); ++i) {
            if (getState(light[i], state, i + 1)) ++ret;
        }
        return ret;
    }
    bool getState(int n, vector<int>& state, int k) {
        int i = n + 1;
        if (state[n - 1] == -1) {
            state[n] = -1;
            for (; i != state.size() && state[i]; ++i) state[i] = -1;
        } else {
            state[n] = 1;
        }
        return state[k] == -1;
    }
};
