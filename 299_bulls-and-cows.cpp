class Solution {
public:
    string getHint(string secret, string guess) {
        int countsS[10] = {0}, countsG[10] = {0};
        int A = 0, B = 0;
        for (int i = 0; i != secret.size(); ++i) {
            if (secret[i] == guess[i]) ++A;
            countsS[secret[i] - '0']++;
            countsG[guess[i] - '0']++;
        }
        for (int i = 0; i < 10; ++i) B += min(countsS[i], countsG[i]);
        stringstream ss;
        ss << A << 'A' << (B - A) << 'B';
        return ss.str();
    }
};
