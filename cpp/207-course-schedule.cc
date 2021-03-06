class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> parents; // a list of nodes that key depends on.
        unordered_map<int, unordered_set<int>> children;  // a list of nodes that depens on key.
        
        for (auto& v : prerequisites) {
            parents[v[0]].insert(v[1]);
            children[v[1]].insert(v[0]);
        }
        
        queue<int> q;
        for (int i=0;i<numCourses;i++) {
            if (parents[i].empty()) {
                q.push(i);
            }
        }
        
        int count = 0;
        while (!q.empty()) {
            int len = q.size();
            
            for (int i=0;i<len;i++) {
                int cur = q.front(); q.pop();
                count++;
                for (auto c : children[cur]) {
                    parents[c].erase(cur);
                    if (parents[c].empty()) {
                        q.push(c);
                    }
                }    
            }
        }
        
        return count==numCourses;
    }
};
