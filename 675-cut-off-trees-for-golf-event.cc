class Solution {
public:
    typedef tuple<int, int, int> POS;
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(); int n = forest[0].size();
        
        vector<POS> v;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (forest[i][j]>1) {
                    v.push_back({forest[i][j], i, j});
                }
            }
        }
        sort(v.begin(), v.end());
        int res = 0;
        int x = 0; int y = 0;
        for (int i=0;i<v.size();i++) {
            int dest_x = get<1>(v[i]);
            int dest_y = get<2>(v[i]);
            int dist = getDist(forest, x, y, dest_x, dest_y);
            if (dist==-1) return -1;
            else res+= dist;
            x = dest_x; y = dest_y;
        }
        
        return res;
    }
    
    int getDist(vector<vector<int>>& forest, int x, int y ,int dest_x, int dest_y) {
        if (x==dest_x && y==dest_y) return 0;
        int m = forest.size(); int n = forest[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = true;
        vector<int> dir = {-1, 0, 1, 0, -1};
        
        int step = 0;
        while (!q.empty()) {
            int len = q.size();
            for (int i=0;i<len;i++) {
                auto cur = q.front(); q.pop();

                for (int j=0;j<4;j++) {
                    int xx = cur.first + dir[j];
                    int yy = cur.second + dir[j+1];
                    if (xx<0 || xx>=m || yy<0 || yy>=n || forest[xx][yy]==0 || visited[xx][yy])  continue;                        
                    if (xx== dest_x && yy ==dest_y) {return step+1;}
                    visited[xx][yy] = true;
                    q.push({xx, yy});
                }
            }
            step++;
        }
        
        return -1;
    }
};
