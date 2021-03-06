class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> set(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> q;
        if (set.count("0000")==0) {
            q.push("0000");
            visited.insert("0000");            
        }

        int step = 0;
        while (!q.empty()) {
            int len = q.size();
            for (int i=0;i<len;i++) {
                string cur = q.front(); q.pop();    
                if (cur==target) { return step; }
                for (int j=0;j<cur.size();j++) {
                    char c = cur[j];
                    int digit = c-'0';
                    int next = (digit+1)%10;
                    int prev = (digit-1+10)%10;
                    
                    cur[j] = '0'+next;
                    if (set.count(cur)==0 && visited.count(cur)==0) {
                        visited.insert(cur);
                        q.push(cur);
                    }
                    cur[j] = '0'+prev;
                    if (set.count(cur)==0 && visited.count(cur)==0) {
                        visited.insert(cur);
                        q.push(cur);
                    }
                    cur[j] = c;
                }
            }    
            step++;
        }
        return -1;
    }
};
