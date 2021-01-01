class Solution {
public:
    // monotonic queue O(N)
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        int res = INT_MIN;
        
        deque<int> q;  // decreasing queue. 
        deque<int> idx;    
        for (int i=0;i<n;i++) {
            int val = nums[i];
        
            while (!idx.empty() && (i-idx.front()>k) ) {
                q.pop_front();
                idx.pop_front();
            }
            
            int cur = val;
            if (!q.empty() && q.front()>0 ) {
                cur += q.front();
            }
            res = max(cur, res);            
            
            while (!q.empty() && cur >= q.back()) {
                q.pop_back();
                idx.pop_back();
            }
            q.push_back(cur);
            idx.push_back(i);
        }
        
        return res;
    }
    
    
//     // O(N*K) TLE
//     int constrainedSubsetSum(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> dp(n, INT_MIN);
//         int res = INT_MIN;
        
//         for (int i=0;i<n;i++) {
//             if (dp[i]==INT_MIN) {
//                 dp[i] = nums[i];
//             } else {
//                 dp[i] += nums[i];
//             }
//             res = max(res, dp[i]);
            
//             if (dp[i]<=0) continue;
            
//             for (int j=i+1;j<=i+k && j<n;j++ ) {
//                 if (dp[j]==INT_MIN) {
//                     dp[j] = dp[i];
//                 } else {
//                     dp[j] = max(dp[j], dp[i]);
//                 }
//             }
//         }
        
//         return res;
//     }
};
