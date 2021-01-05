class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        vector<int> idx(n+1);
        for (int i=0;i<n;i++) {idx[org[i]]=i; }
        
        unordered_map<int, unordered_set<int>> parents; // parents
        unordered_map<int, unordered_set<int>> children; // children

        for (auto& seq : seqs) {
            for (int i=0;i<seq.size();i++) {
                if (seq[i]>n || seq[i]<1) return false;  // element should exist in original sequence
                if (i==0) {
                    parents[seq[i]];    
                }
                else {
                    if (idx[seq[i]]<=idx[seq[i-1]]) return false; // consecutive elements should exist in the original sequence.
                    if (parents[seq[i]].count(seq[i-1])==0) {
                        parents[seq[i]].insert(seq[i-1]);
                        children[seq[i-1]].insert(seq[i]);
                    }                    
                }
            }
        }
        
        queue<int> q;
        
        for (auto&[key, set] : parents) {
            if (set.size() == 0) {
                q.push(key);
            }
        } 
        int count = 0;
        while (!q.empty()) {
            int len = q.size();
            if (len>1) return false;
            
            for (int i=0;i<len;i++) {
                int cur = q.front(); q.pop();
                count++;
                for (auto child : children[cur]) {
                    parents[child].erase(cur);
                    if (parents[child].size() ==0) {
                        q.push(child);
                    }
                }
            }
        }
        return count == org.size();
    }
};
