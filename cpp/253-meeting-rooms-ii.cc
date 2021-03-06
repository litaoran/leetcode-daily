class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        priority_queue<int, vector<int>, std::greater<int>> q;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int> b){return a[0]<b[0]; });
        
        int res = 0;
        
        for (auto& interval : intervals) {
            int s = interval[0]; 
            int e = interval[1]; 
            
            while (!q.empty() && s >= q.top()) {q.pop(); }
            q.push(e);
            res= std::max(res, (int)q.size());
        }
        return res;
    }
};
