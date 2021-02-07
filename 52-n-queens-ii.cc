class Solution {
public:

    int totalNQueens(int n) {

        vector<bool> cols(n);
        vector<bool> diag1(2*n);
        vector<bool> diag2(2*n);
        
        int res = 0;
        dfs(0, res, cols, diag1, diag2);
        return res;
    }
    
    void dfs(int row, int& res, vector<bool>& cols, vector<bool>& diag1,  vector<bool>& diag2) {
        int n = cols.size();
        
        if (row==n) {
            res++;
            return;
        }
        
        for (int j=0;j<n;j++) {
            if (cols[j]) continue;
            if (diag1[row+j]) continue;
            if (diag2[j-row+n]) continue;

            cols[j] = true;
            diag1[row+j] = true;
            diag2[j-row+n] = true;
                    
            dfs(row+1, res, cols, diag1, diag2);
            
            cols[j] = false;
            diag1[row+j] = false;
            diag2[j-row+n] = false;
            
        }
    }
};
