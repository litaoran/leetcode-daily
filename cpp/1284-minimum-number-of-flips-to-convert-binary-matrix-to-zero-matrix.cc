class Solution {
public:
    vector<vector<int>> dirs{{-1,0},{1,0},{0,1},{0,-1},{0,0}};
    
    int getFlippedMask(int mask, int i, int j, int m, int n) {
        for (auto dir: dirs) {
            int x = i+dir[0]; int y = j+dir[1];
            if (x<0 || x>=m || y<0 || y>=n) {
                continue;
            }
            int idx = x*n + y;
            mask ^= (1<<idx);
        }
        return mask;
    }
    
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size(); int n = mat[0].size();
        
        
        unordered_map<int, int> min_step;
        int mask = 0;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                int idx = i*n+j;
                if (mat[i][j]) mask |= (1<<idx);
            }
        }
        min_step[mask] = 0;
        
        int step = 0;
        queue<int> q; q.push(mask); 
        while (!q.empty()) {
            int len = q.size();
            for (int k=0;k<len;k++) {
                int mask = q.front(); q.pop();
                if (mask==0) {return min_step[mask]; }
                for (int i=0;i<m;i++) {
                    for (int j=0;j<n;j++) {
                        int new_mask = getFlippedMask(mask, i, j, m, n);           
                        if (min_step.count(new_mask)==0) {
                            min_step[new_mask]= step+1;
                            q.push(new_mask);
                        }
                    }
                }
            }
            step++;
            
        }
        return -1;
    }
};
