class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> blocks(9);
        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                if (board[i][j]=='.') {continue;}
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                int idx = i/3*3 + j/3;
                blocks[idx].insert(board[i][j]);
            }
        }
        
        dfs(board, 0,0,rows, cols, blocks);
        
    }
    
    
    bool dfs(vector<vector<char>>& board, int i, int j, vector<unordered_set<char>>& rows, vector<unordered_set<char>>& cols, vector<unordered_set<char>>& blocks) {
        
        if (i == 9) {
            return true;
        } 
        if (j==9) {
            return dfs(board, i+1, 0, rows, cols, blocks);
        }
        
        if (board[i][j]!='.') {
            return dfs(board, i, j+1, rows, cols, blocks);
        }
        
        int idx = i/3*3 + j/3; 
        for (char c = '1';c<='9';c++) {
            if (rows[i].count(c)!=0 || cols[j].count(c)!=0 || blocks[idx].count(c)!=0) {
                continue;
            }
            rows[i].insert(c);
            cols[j].insert(c);
            blocks[idx].insert(c);
            
            board[i][j] = c;
            if (dfs(board, i, j+1, rows, cols, blocks)) {
                return true;
            }
            board[i][j] = '.';
                
            rows[i].erase(c);
            cols[j].erase(c);
            blocks[idx].erase(c);
            
        }
        
        return false;
    }
    
};
