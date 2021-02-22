class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        dfs(s, 0, cur, res);
        return res;
    }
    
    void dfs(string s, int idx, vector<string>& cur, vector<vector<string>>& res) {
        
        if (idx==s.size()) {
            res.push_back(cur);
            return;
        }
        
        
        for (int i=idx;i<s.size();i++) {
            if (isP(s, idx, i)) {
                cur.push_back(s.substr(idx, i-idx+1));
                dfs(s, i+1, cur, res);
                cur.pop_back();
            }
        }

    }
    bool isP(string s, int l, int r) {
        while (l<r) {
            if (s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
