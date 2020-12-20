class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_set<int> set1, set2;    
        
        for (int i=0;i<graph.size();i++) {
            bool res = dfs(graph, i, true, set1, set2);
            if (!res) {
                return false;
            }
        }

        return true;
    }
    
    bool dfs(vector<vector<int>>& graph, int cur, bool is_set1, unordered_set<int>& set1, unordered_set<int>& set2) {
        if (set1.count(cur)!=0 || set2.count(cur)!=0) {
            return true;
        }
        
        if (is_set1) {
            set1.insert(cur);
        } else {
            set2.insert(cur);
        }
        
        for (auto next : graph[cur]) {
            if (is_set1 && set1.count(next) != 0) {
                return false;
            }
            if (!is_set1 && set2.count(next) != 0) {
                return false;
            }
            
            bool tmp = dfs(graph, next, !is_set1, set1, set2);
            if (!tmp) return false;
        }
        
        return true;
    }
};
