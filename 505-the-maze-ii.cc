class Solution {
public:
    // Dijkstra. Find the shortest path.
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false)); 
        
        auto cmp = [](vector<int>& a, vector<int>& b) {return a[2] > b[2]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);  // min heap
        
        q.push({start[0], start[1], 0});
        vector<vector<int>> dirs{{-1,0},{1,0},{0,-1},{0,1}};   
        while (!q.empty()) {
            auto cur = q.top(); q.pop();
            int x = cur[0]; int y = cur[1]; int len = cur[2];  
            if (visited[x][y]) continue;
            visited[x][y] = true;
            if (x==destination[0] && y==destination[1]) return len;     

            for (auto dir : dirs) {        
                int xx = x + dir[0]; 
                int yy = y + dir[1];
                int cost = 0;
                while (xx>=0 && xx<m && yy>=0 && yy<n && maze[xx][yy]==0) {
                    xx += dir[0];
                    yy += dir[1];
                    cost++;
                }
                xx -= dir[0];
                yy -= dir[1];
                if (visited[xx][yy]) { continue;}
                q.push({xx,yy, cost+len});
            }
            
        }
        
        return -1;
    }
};
