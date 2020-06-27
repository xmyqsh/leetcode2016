class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        deque<int> dq;
        dq.push_front(deck.back());
        for (int i = deck.size() - 2; i != -1; --i) {
            dq.push_front(dq.back()); dq.pop_back();
            dq.push_front(deck[i]);
        }
        vector<int> result; result.reserve(deck.size());
        while (!dq.empty()) { result.push_back(dq.front()); dq.pop_front(); }
        return result;
    }
};
