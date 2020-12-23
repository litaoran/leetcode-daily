class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> set;
        
        return dfs(set, s);
    }
    
    int dfs(unordered_set<string>& set, string s) {
        if (s.empty()) {
            return 0;
        }
        
        int res = -1;
        for (int i=0;i<s.size();i++) {
            string subs = s.substr(0, i+1);
            if (set.count(subs) !=0) {
                continue;
            }
            string left = s.substr(i+1, s.size() - (i+1));
            
            set.insert(subs);
            res = max(res, dfs(set, left) + 1);
            set.erase(subs);
        }
        
        return res;
        
    }
};
