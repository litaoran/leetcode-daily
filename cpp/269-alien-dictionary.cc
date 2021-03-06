class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> children;
        unordered_map<char, int> indegree;
        
        // Initialize each existing character.
        for (auto word : words) {
            for (auto ch : word) {
                indegree[ch];
            }
        }
        
        // Build graph
        for (int i=0; i<words.size()-1; i++) {
            string s1 = words[i];  string s2 = words[i+1];
            bool found_diff = false;
            for (int j=0;j<min(s1.size(), s2.size()); j++) {
                if (s1[j] != s2[j]) {
                    if (children[s1[j]].count(s2[j])==0) {
                        children[s1[j]].insert(s2[j]);            
                        indegree[s2[j]]++;
                    }
                    found_diff = true;
                    break;
                }
            }
            if (found_diff==false && s1.size()> s2.size()) {return "";} // Cornor case: ["abc","ab"]
        }
        
        // Topological Sort
        string res = "";
        queue<char> q;
        for (auto& [ch, d] : indegree) {
            if (d==0) { 
                q.push(ch); 
            }
        }
        while (!q.empty()) {
            int len = q.size();
            for (int i=0;i<len;i++) {
                char cur = q.front(); q.pop();
                res = res + cur;
             
                for (char c : children[cur]) {
                    indegree[c]--;
                    if (indegree[c]==0) {
                        q.push(c);
                    }
                }
            }
        }
        
        // Diff exists
        return res.size()==indegree.size()? res : "";
    }
};
