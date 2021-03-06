class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        vector<bool> visited(n);
        
        queue<int> q;
        q.push(id);
        visited[id] = true;
        int step = 0;
        unordered_set<int> candidates;
        while (!q.empty()) {
            int len = q.size();
            bool find = (step==level);
            for (int i=0;i<len;i++) {
                int  cur = q.front(); q.pop();    
                if (find) {
                    candidates.insert(cur);
                }
                
                for (auto f : friends[cur]) {
                    if (visited[f]) continue;
                    visited[f] = true;
                    q.push(f);
                } 
            }
            if (find) break;
            step++;
        }
        
        unordered_map<string, int> freq;
        for (auto& c : candidates) {
            for (auto v : watchedVideos[c]) {
                freq[v]++;
            }
        }

        vector<pair<int, string>> v; 
        for (auto& [video, cnt] : freq) {
            v.push_back({cnt, video});
        }
        sort(v.begin(), v.end());
        vector<string> res;
        for (auto& [cnt, video] : v) {
            res.push_back(video);
        }
        return res;
    }
};
