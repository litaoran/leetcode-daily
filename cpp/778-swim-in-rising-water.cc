class Solution {
public:
    // Graph - Dijkstra
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        
        // v[i] : x1,x2,elevation    
        auto cmp = [](vector<int>& a, vector<int>& b){ return a[2]>b[2]; };
        priority_queue<vector<int>, vector<vector<int>>,  decltype(cmp)> q(cmp);  //min heap
        
        
        vector<vector<bool>> enqueue(m, vector<bool>(n,false));
        q.push({0,0,grid[0][0]});
        enqueue[0][0] = true;
        
        vector<vector<int>> dirs{{-1,0},{1,0},{0,-1},{0,1}};
        int time = 0;
        while (!q.empty()) {
            auto cur = q.top(); q.pop();
            int x = cur[0]; int y = cur[1];  int elevation = cur[2];
            time = max(time, elevation);
            if (x==m-1 && y==n-1) {return time;}
            
            for (auto dir : dirs) {
                int newx = x+dir[0];
                int newy = y+dir[1];
                
                if (newx<0||newx>=m||newy<0||newy>=n||enqueue[newx][newy]) {
                    continue;
                }
                q.push({newx, newy, grid[newx][newy]});
                enqueue[newx][newy] = true;
            }
            
        }
        
        return -1;
    }
};
