class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;       
        dfs(1, {}, k, n, res);
        return res;
    }
    
    void dfs(int digit, vector<int> cur, int k, int n, vector<vector<int>>& res) {
        if (n<0) {return ;}
        if (n==0) {
            if (k==cur.size()) {
                res.push_back(cur);
            }
            return;
        }
        if (digit>9) {return ;}
        
        dfs(digit+1, cur, k, n, res);
        cur.push_back(digit);
        dfs(digit+1, cur, k, n-digit, res);
    }
};
