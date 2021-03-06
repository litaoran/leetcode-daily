class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(0, 0, 0, n, "", res);    
        return res;
    }
    
    void dfs(int idx, int l, int r, int n,string cur, vector<string>& res) {
        
        if (idx==2*n) {
            res.push_back(cur);
            return;
        }
        
        if (l<n) {
            dfs(idx+1, l+1, r, n, cur+'(', res);
        }
        if (l>r && r<n) {
            dfs(idx+1, l, r+1, n, cur+')', res);
        }
    }
    
};
