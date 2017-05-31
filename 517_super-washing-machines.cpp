class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        if (machines.size() < 2) return 0;
        int sum = 0;
        for (auto machine : machines)
            sum += machine;
        int target = sum / machines.size();
        if (sum != target * machines.size()) return -1;
        int result = 0, balance = 0;
        for (auto machine : machines) {
            balance += machine - target;
            result = max(result, max(machine - target, abs(balance)));
        }
        return result;
    }
};

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        if (machines.size() < 2) return 0;
        int sum = 0;
        for (auto machine : machines)
            sum += machine;
        int target = sum / machines.size();
        if (sum != target * machines.size()) return -1;
        int result = 0, toLeft = 0;
        for (auto machine : machines) {
            int toRight = machine - toLeft - target;
            result = max(result, max(max(toLeft, toRight), toLeft + toRight));
            toLeft = -toRight;
        }
        return result;
    }
};
