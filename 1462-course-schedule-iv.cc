class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    
        
        vector<vector<int>> reachable(n, vector<int>(n, 0));
        unordered_map<int, unordered_set<int>> children;

        for (auto& prerequisite :  prerequisites) {
            int first = prerequisite[0]; int second = prerequisite[1]; 
            children[first].insert(second);
        }
        
        for (int i=0;i<n;i++) {
            queue<int> q; q.push(i);

            while (!q.empty()) {
                int len = q.size();
                for (int j=0;j<len;j++) {
                    int cur = q.front(); q.pop();
                    for (auto child : children[cur]) {
                        if (reachable[i][child]!=0) continue;  // this check will detect the circle
                        reachable[i][child] = 1;
                        q.push(child);
                    }
                }
            }
        }
        
        vector<bool> res(queries.size());
        for (int i=0;i<queries.size();i++) {
            auto q = queries[i];
            res[i] = (reachable[q[0]][q[1]]==1);
        }
        return res;
        
    }
};
