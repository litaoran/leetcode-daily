class Solution {
public:
    // When meet ladder, directly jumps to the destination and only stores the destination of the ladder.
    int snakesAndLadders(vector<vector<int>>& board) {        
        int n = board.size();
        vector<bool> visited(n*n+1, false);
        
        queue<int> q;
        q.push(1);
        visited[1]= true;
        
        int step = 0;
        while (!q.empty()) {
            int len = q.size();
            for (int i=0;i<len;i++) {
                int cur = q.front(); q.pop();
                if (cur==n*n) {return step;}
                
                for (int i=1;i<=6;i++) {
                    int next = cur + i;                
                    if (next>n*n) continue;
                    
                    int x = n-1-(next-1)/n;  
                    int y;
                    if ((next-1)/n%2==0) {
                        y = (next-1)%n;
                    } else {
                        y = n-1 -(next-1)%n;
                    }
                    if (board[x][y]!=-1) {
                        next = board[x][y];
                    }
                    if (visited[next]) continue;
                    visited[next] = true;
                    q.push(next);
                }   
            }
            step++;
        }
        return -1;
        
    }
};
