class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        
        dfs({}, 1, n, k, res);
        
        return res;
    }
    
    void dfs(vector<int> cur, int idx, int n, int k, vector<vector<int>>& res) {
        if (k==0) {
            res.push_back(cur);
            return;
        }
        
        for (int i=idx;i<=n;i++) {
            cur.push_back(i);
            dfs(cur, i+1, n, k-1, res);
            cur.resize(cur.size()-1);
        }
    }
};
