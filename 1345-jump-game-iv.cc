class Solution {
public:
    
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> parent(n);
        for (int i=0;i<n;i++) {parent[i] = i;}
        
        
        unordered_map<int, unordered_set<int>> map;
        for (int i=0;i<arr.size();i++) {
            map[arr[i]].insert(i);
        }
        
        queue<int> q; q.push(0);
        vector<bool> visited(n);
        visited[0] = true;
        int step = 0;
        while (!q.empty()) {
            int len = q.size();
            for (int i=0;i<len;i++) {
                int cur = q.front(); q.pop();
                if (cur==n-1) {return step;}
                for (auto idx : map[arr[cur]]) {
                    if (visited[idx]) {continue;}
                    visited[idx] = true;
                    q.push(idx);   
                }
                int next = cur+1;
                if (next<n && !visited[next]) {
                    visited[next] = true;
                    q.push(next);    
                }
                int prev = cur-1;
                if (prev>=0 && !visited[prev]) {
                    visited[prev] = true;
                    q.push(prev);    
                }
                map.erase(arr[cur]);
            }
            step++;
           
        }
        return -1;
    }
};
