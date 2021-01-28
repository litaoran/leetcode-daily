class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        if (matrix.size()==0 || matrix[0].size()==0) {return res;}
        int m = matrix.size(); int n = matrix[0].size();
        
        // units which are reachable to Pacific        
        vector<vector<bool>> p_reached(m, vector<bool>(n));
        queue<pair<int, int>> p_q;
        for (int i=0;i<m;i++) {
            p_q.push({i, 0});
            p_reached[i][0] = true;
        }
        for (int j=1;j<n;j++) {
            p_q.push({0, j});
            p_reached[0][j] = true;
        }
        vector<vector<int>> dirs{{-1,0}, {1,0}, {0,-1},{0,1}};
        while (!p_q.empty()) {
            auto cur = p_q.front(); p_q.pop();
            int x = cur.first; int y = cur.second;
            p_reached[x][y] = true;
            for (auto dir : dirs) {
                int xx = x + dir[0];
                int yy = y + dir[1];
                if (xx<0 || xx>=m || yy<0 || yy>=n || p_reached[xx][yy] ) continue;
                if (matrix[xx][yy]<matrix[x][y]) {
                    continue;
                }
                p_q.push({xx, yy});  p_reached[xx][yy]  = true;
            }
        }
        
        // units which are reachable to Atlantic
        vector<vector<bool>> a_reached(m, vector<bool>(n));
        queue<pair<int, int>> a_q;
        for (int i=0;i<m;i++) {
            a_q.push({i, n-1});
            a_reached[i][n-1] = true;
        }
        for (int j=0;j<n-1;j++) {
            a_q.push({m-1, j});
            a_reached[m-1][j] = true;
        }
        while (!a_q.empty()) {
            auto cur = a_q.front(); a_q.pop();
            int x = cur.first; int y = cur.second;
            for (auto dir : dirs) {
                int xx = x + dir[0];
                int yy = y + dir[1];
                if (xx<0 || xx>=m || yy<0 || yy>=n || a_reached[xx][yy]) continue;
                if (matrix[xx][yy]<matrix[x][y]) {
                    continue;
                }
                a_q.push({xx, yy});  a_reached[xx][yy] = true;
            }
        }
        
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (a_reached[i][j] && p_reached[i][j]) {
                    res.push_back({i,j});    
                }
            }
        }
        return res;
        
    }
};
