class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> forbidden_set(forbidden.begin(), forbidden.end());
        
        int Size = 6001;
        
        int cur = 0;
        queue<pair<int, bool>> q;
        // Actually, we could use visited set here. But we need to store direction as well since the visit direction of each pos also affect the next state.
        vector<int> left_jumps(Size, INT_MAX);  // from left to current
        vector<int> right_jumps(Size, INT_MAX); // from right to current 
        left_jumps[0] = 0;
        right_jumps[0] = 0;
        
        q.push({0, false});
        while (!q.empty()) {
            int len = q.size();
            for (int i=0;i<len;i++) {
                auto node = q.front(); q.pop();
                
                int pos = node.first;
                bool last_back = node.second;
                
                if (pos==x) {
                    if (left_jumps[pos]!=INT_MAX || right_jumps[pos]!=INT_MAX){
                        return min(left_jumps[pos], right_jumps[pos]);
                    }
                }
               
                // Test go forward
                if (pos+a<Size && forbidden_set.count(pos+a)==0) {
                    int step = min(left_jumps[pos], right_jumps[pos]);
                    if (step +1 <left_jumps[pos+a]) {
                        left_jumps[pos+a] = step +1;
                        q.push({pos+a, false});
                    }
                }
                
                // Test go backward
                if (last_back==false) {
                    if (pos-b>0 && forbidden_set.count(pos-b)==0) {
                        int step = left_jumps[pos];
                        if (step +1 <right_jumps[pos-b]) {
                            right_jumps[pos-b] = step +1;
                            q.push({pos-b, true});
                        }
                    }
                }
            }
        }
        
        return -1;   
    }
};
