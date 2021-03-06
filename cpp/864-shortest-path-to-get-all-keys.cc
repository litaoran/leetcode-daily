class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(); int n = grid[0].size();
        unordered_map<char, pair<int, int>> locks;
        
        unordered_map<int, unordered_map<int, unordered_map<string, bool>>> visited;
        queue<tuple<int, int, string>> q;
        int total = 0;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j]=='@') {
                    q.push({i, j, ""});
                    visited[i][j][""]=true;
                }
                if (islower(grid[i][j])) total++;
            }
        }
        
        vector<vector<int>> dirs{{-1,0},{1,0},{0,1},{0,-1}};
        
        int step = 0;
        while (!q.empty()) {
            int len = q.size();
            
            for (int i=0;i<len;i++) {
                auto cur = q.front(); q.pop();
                int x = get<0>(cur); int y = get<1>(cur);  string key = get<2>(cur);
                // cout << "x: " << x << " y: " << y << " key: " << key << endl;    
                
                if (key.size()==total) return step;

                for (auto dir : dirs) {
                    int xx = x + dir[0];
                    int yy = y + dir[1];                  
                    if (xx<0 || xx>=m || yy <0 || yy>=n || visited[xx][yy][key] || grid[xx][yy]=='#') {
                        continue;
                    }
        
                    if (islower(grid[xx][yy])) {
                        set<char> new_set(key.begin(), key.end());
                        new_set.insert(grid[xx][yy]);
                        string new_key(new_set.begin(), new_set.end());
                        if (visited[xx][yy][new_key]) continue;                    
                        q.push({xx, yy, new_key});
                        visited[xx][yy][new_key] = true;
                    } else if(isupper(grid[xx][yy])) {
                        unordered_set<char> new_set(key.begin(), key.end());
                        if (new_set.count(tolower(grid[xx][yy]))) {
                            q.push({xx, yy, key});
                            visited[xx][yy][key] = true;
                        } else {
                            continue;    
                        }
                    } else if (grid[xx][yy]=='.' || grid[xx][yy]=='@') {
                        q.push({xx, yy, key});
                        visited[xx][yy][key] = true;
                    } else {
                        assert(false);
                    }
                }                
            }
            step++;
        }
        return -1;
        
    }
};
