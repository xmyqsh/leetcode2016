class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> qr, qd;
        int n = senate.size();
        for (int i = 0; i != senate.size(); ++i) {
            if (senate[i] == 'R') qr.push(i);
            else qd.push(i);
        }
        while (!qr.empty() && !qd.empty()) {
            if (qr.front() < qd.front()) {
                qd.pop();
                qr.push(qr.front() + n);
                qr.pop();
            } else {
                qr.pop();
                qd.push(qd.front() + n);
                qd.pop();
            }
        }
        return qr.empty() ? "Dire" : "Radiant";
    }
};
