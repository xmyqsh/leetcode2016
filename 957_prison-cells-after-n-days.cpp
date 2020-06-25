class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        unordered_map<int, int> stateStart;
        stateStart[encode(cells)] = 0;
        for (int i = 1; i != N + 1; ++i) {
            nextState(cells);
            int state = encode(cells);
            if (stateStart.count(state)) {
                int period = i - stateStart[state];
                if (N % period == stateStart[state]) return cells;
                i += (N - i) / period * period;
            } else stateStart[state] = i;
        }
        return cells;
    }
    void nextState(vector<int>& cells) {
        vector<int> nextCells(8, 0);
        for (int i = 1; i != 7; ++i) {
            nextCells[i] = cells[i - 1] == cells[i + 1] ? 1 : 0;
        }
        swap(cells, nextCells);
    }
    int encode(const vector<int>& cells) {
        int state = 0;
        for (int i = 0, base = 1; i != 8; ++i, base <<= 1) {
            if (cells[i]) state |= base;
        }
        return state;
    }
    vector<int> decode(int state) {
        vector<int> cells(8);
        for (int i = 0, base = 1; i != 8; ++i, base <<= 1) {
            cells[i] = ((state & base) >> i);
        }
        return cells;
    }
};
