class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, unordered_set<int>> followers;
        
        int root = -1;
        for (int i=0;i<n;i++) {
            if (manager[i]==-1) { root = i; continue; }
            followers[manager[i]].insert(i);
        }
        return getTime(followers, informTime, root);
    }
    
    int getTime(unordered_map<int, unordered_set<int>>& followers, vector<int>& informTime, int cur) {
        if (followers[cur].empty()) {
            return 0;
        }
        
        int time = 0;
        for (auto follower : followers[cur]) {
            time = max(time, getTime(followers, informTime, follower));
        }
        time += informTime[cur];
        return time;
    }
    
    
};
