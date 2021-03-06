class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    
        vector<int> indegree(numCourses);
        unordered_map<int, unordered_set<int>> g;  // key -> courses that depend on key
        
        for (auto& p : prerequisites) {
            indegree[p[0]]++;    // order p[1] -> p[0];
            g[p[1]].insert(p[0]);
        }
        
        queue<int> q;
        for (int i=0;i<numCourses;i++) {
            if (indegree[i]==0) {q.push(i);}
        }
        
        vector<int> res;
        while (!q.empty()) {
            int len = q.size();
            for (int i=0;i<len;i++) {
                int cur = q.front(); q.pop();
                res.push_back(cur);
   
                for (auto child : g[cur]) {
                    indegree[child]--;
                    if (indegree[child]==0) {
                        q.push(child);
                    }
                }
            }
        }
        
        return res.size()==numCourses? res: vector<int>();
    }
};
