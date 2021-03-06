class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {

        vector<bool> cols(n);
        vector<bool> diag1(2*n);
        vector<bool> diag2(2*n);
        vector<vector<string>> res;
        vector<string> cur(n, string(n, '.'));
        
        dfs(cur, 0, res, cols, diag1, diag2);
        return res;
    }
    
    void dfs(vector<string>& cur, int row, vector<vector<string>>& res, vector<bool>& cols, vector<bool>& diag1,  vector<bool>& diag2) {
        int n = cur.size();
        
        if (row==n) {
            res.push_back(cur);
            return;
        }
        
        for (int j=0;j<n;j++) {
            if (cols[j]) continue;
            if (diag1[row+j]) continue;
            if (diag2[j-row+n]) continue;

            cols[j] = true;
            diag1[row+j] = true;
            diag2[j-row+n] = true;
                    
            cur[row][j] = 'Q';
            dfs(cur, row+1, res, cols, diag1, diag2);
            cur[row][j] = '.';
            
            cols[j] = false;
            diag1[row+j] = false;
            diag2[j-row+n] = false;
            
        }
    }

};
