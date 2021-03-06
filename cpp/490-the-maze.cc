class Solution {
public:
    
    // The ball need to stop there, so we only foces on the spots that we could really stop!!
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false)); 
        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        visited[start[0]][start[1]] = true;        
        vector<vector<int>> dirs{{-1,0},{1,0},{0,-1},{0,1}};        
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            int x = cur.first; int y = cur.second;  
            
            if (x==destination[0] && y==destination[1]) return true;     
            
            for (auto dir : dirs) {        
                int xx = x + dir[0]; 
                int yy = y + dir[1];
                while (xx>=0 && xx<m && yy>=0 && yy<n && maze[xx][yy]==0) {
                    xx += dir[0];
                    yy += dir[1];
                }
                xx -= dir[0];
                yy -= dir[1];
                if (visited[xx][yy]) { continue;}
                
                q.push({xx,yy});
                visited[xx][yy] = true;
            }    
        }
        
        return false;
    }
};
