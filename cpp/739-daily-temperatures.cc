class Solution {
public:
    // Monotonic stack;
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n);
        
        stack<int> s;
        stack<int> s_idx;
        
        for (int i=n-1;i>=0;i--) {    
            int val = T[i];
            while (!s.empty() && val>=s.top()) {
                s.pop();
                s_idx.pop();
            }
            if (!s.empty()) {
                res[i] = s_idx.top() - i;
            }
            
            s.push(val);    
            s_idx.push(i);
            
        }
        
        return res;
    }
};
