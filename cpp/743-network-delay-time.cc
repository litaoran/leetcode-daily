class Solution {
public:
    // Djikstra: put node_id and distance into the map.
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int, unordered_map<int, int>> graph;
        for (auto& time : times) {
            graph[time[0]][time[1]] = time[2];
        }
        
        auto cmp = [](pair<int, int>& a, pair<int, int>& b) { return a.second > b.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> min_heap(cmp); 
                
        unordered_set<int> visited;
        min_heap.push({K, 0});
        
        while (!min_heap.empty()) {
            auto cur = min_heap.top(); min_heap.pop();
            if (visited.count(cur.first)!=0) continue;
            visited.insert(cur.first);    
            if (visited.size()==N) return cur.second;
            
            for (auto& [neighbor, time] : graph[cur.first]) {
                min_heap.push({neighbor, cur.second+time});
            }
        }
        return -1;
    }
};
