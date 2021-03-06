class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int n = A.size();
        if (n <= 1) return 0;
        
        int res = 0;
        // stack stores the start point of the ramp
        stack<int> s;
        for (int i=0;i<n;i++) {
            if (s.empty() || A[i] < A[s.top()] ) {
                s.push(i);
            }
        }
        
        // i the end point of the ramp.
        for (int i=n-1;i>=0;i--) {
            while (!s.empty() && A[i]>=A[s.top()]) {
                res = max(res, i-s.top()); 
                s.pop();
            }    
        }
        return res;
    }
};
