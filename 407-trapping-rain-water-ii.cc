class Solution {
public:
    typedef tuple<int, int, int> Node;
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(); int n = heightMap[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<Node, vector<Node>, greater<Node>> q;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (i==0 || j==0 || i==m-1 ||j==n-1) {
                    q.push({heightMap[i][j], i, j});
                    visited[i][j] = true;
                }
            }    
        }
        
        int res = 0;
        vector<vector<int>> dirs{{-1,0}, {1,0},{0,1},{0, -1}};
        while (!q.empty()) {
            auto node = q.top();  q.pop();
            int h = get<0>(node); int x = get<1>(node); int y = get<2>(node);
            for (auto dir : dirs) {
                int xx = x + dir[0];
                int yy = y + dir[1];
                if (xx<0 || xx>=m || yy<0 || yy>=n || visited[xx][yy]) {continue; }
                
                visited[xx][yy] = true;
                if (h > heightMap[xx][yy]) {
                    res += h - heightMap[xx][yy];
                }
                q.push({max(heightMap[xx][yy], h), xx, yy});
            }
        }
        
        return res;
    }
};
