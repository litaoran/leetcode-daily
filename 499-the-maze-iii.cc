class Solution {
public:
    class POS{
      public:  
        int x = -1;
        int y = -1;
        int l = INT_MAX;
        string path = "";
        POS() = default;
        POS(int l, int x, int y, string path) {
            this->x = x;
            this->y = y;
            this->l = l;
            this->path = path;
        }
        
        bool operator()(POS& left, POS& right) { 
            if (left.l!=right.l) {
                return left.l> right.l;  
            } else {
                return left.path > right.path;
            }
        }
    };
    
    // some tips to solve the problem
    // 1. Consider the hole as a special node and store states for it like other cornor nodes
    // 2. Always store the path within each state
    // 3. When runing Dijkstra algroithm, compare the distance first and then the path. Then the first elem popped out from the queue is the result.
    
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size(); int n = maze[0].size();
        
        vector<vector<POS>> postions(m, vector<POS>(n));
        vector<vector<bool>> visited(m, vector<bool>(n));
        
        priority_queue<POS, vector<POS>, POS> q; // min heap
        POS tmp(0, ball[0], ball[1], "");
        q.push(tmp);
        
        vector<vector<int>> dirs{{-1,0},{1,0},{0,1},{0,-1}};
        vector<string> ds{"u","d","r","l"};
        while (!q.empty()) {
            auto cur = q.top(); q.pop();
            int l =cur.l; int x = cur.x; int y = cur.y; string path = cur.path;
            if (visited[x][y]) continue;
            postions[x][y] = cur;
            visited[x][y] = true;
            
            for (int i=0;i<4;i++) {
                auto dir = dirs[i];
                int xx = x; int yy=y;
                int cost = 0;
                while (xx>=0 && xx<m && yy>=0 && yy<n && maze[xx][yy]==0 && (xx!=hole[0] || yy!=hole[1] )) {
                    xx+=dir[0];
                    yy+=dir[1];
                    cost++;
                }
                if (xx!=hole[0] || yy!=hole[1]) {
                    xx-=dir[0];
                    yy-=dir[1];
                    cost--;
                }
                
                if (xx==x && yy==y) continue;
                
                q.push(POS(l+cost, xx, yy, path+ds[i]));
            }
        }
        return visited[hole[0]][hole[1]] ?  postions[hole[0]][hole[1]].path : "impossible";
    }
};
