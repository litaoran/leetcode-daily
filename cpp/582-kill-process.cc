class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, unordered_set<int>> childern;
        
        for (int i=0;i<pid.size();i++) {
            int child = pid[i];
            int parent = ppid[i];
            if (parent==0) {
                continue;
            } else {
                childern[parent].insert(child);
            }
        }
        
        if (childern.count(kill)==0) {
            return vector<int>{kill};
        }
        vector<int> res;
        
        queue<int> q;
        q.push(kill);
        
        while (!q.empty()) {
            int len = q.size();
            for (int i=0;i<len;i++) {
                int cur = q.front(); q.pop();    
                res.push_back(cur);
                
                for (auto next : childern[cur]) {
                    q.push(next);
                }
            }            
        }
        
        return res;
    }
};
