/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        if (!mp.count(node)) {
            mp[node] = new UndirectedGraphNode(node->label);
            for (auto neighbor : node->neighbors)
                mp[node]->neighbors.push_back(cloneGraph(neighbor));
        }
        return mp[node];
    }
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
};
