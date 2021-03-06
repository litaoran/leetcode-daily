class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        
        vector<vector<int>> dists(m, vector<int>(n, INT_MAX));
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
        q.push({0,0,0});
        
        vector<vector<int>> dirs{{-1,0},{1,0},{0,1},{0,-1}};
        while (!q.empty()) {
            auto cur = q.top(); q.pop();
            int x = get<1>(cur); int y = get<2>(cur); int dist = get<0>(cur); 
            if (dists[x][y] <= dist) {continue;}
            dists[x][y] = dist;

            for (auto dir : dirs) {
                int xx = x + dir[0];    
                int yy = y + dir[1];
                if (xx<0|| xx>=m || yy<0 || yy>=n) continue;
                
                bool is_same = false;
                if (grid[x][y]==1 && dir[1]==1) is_same = true;
                if (grid[x][y]==2 && dir[1]==-1) is_same = true;
                if (grid[x][y]==3 && dir[0]==1) is_same = true;
                if (grid[x][y]==4 && dir[0]==-1) is_same = true;
                
                int new_cost = dist + (is_same ? 0: 1);
                q.push({new_cost, xx, yy});
            }
            
        }
        
        return dists[m-1][n-1];
    }
};
