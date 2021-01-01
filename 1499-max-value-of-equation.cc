class Solution {
public:
    
    // Monotonic queue.  Use it when we want the min/max value within a given window.
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair<int, int>> q;
        int res = INT_MIN;
        for (int i=0;i<points.size();i++) {
            int x = points[i][0];
            int y = points[i][1];
            
            while (!q.empty() &&  x- q.front().first>k) {
                q.pop_front();
            }
            if (!q.empty()) {
                auto& front = q.front();
                res = max(res, front.second- front.first + y + x);
            }
            
            // Need to keep the queue strictly decreasing.
            while (!q.empty() && y-x>=  q.back().second-q.back().first ) {
                q.pop_back();
            }
            q.push_back({x, y});
        }
 
        return res;
    }    
    
    
//     // Min heap
//     typedef pair<int, int > pi;
//     int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        
//         auto cmp = [](pi& p1, pi& p2){return (p1.second-p1.first) < (p2.second-p2.first); }; // use max heap
//         priority_queue<pi, vector<pi>, decltype(cmp)> q(cmp);  
        
//         int res = INT_MIN;
//         for (int i=0;i<points.size();i++) {
//             int x = points[i][0];
//             int y = points[i][1];
            
//             while (!q.empty() &&  x- q.top().first>k) {
//                 q.pop();
//             }
//             if (!q.empty()) {
//                 auto& top = q.top();
//                 res = max(res, top.second- top.first + y + x);
//             }
            
//             q.push({x, y});
//         }
 
//         return res;
//     }
};
