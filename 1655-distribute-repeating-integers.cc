class Solution {
public:
    // Bottom up DP
    
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        int m = quantity.size();
        
        map<int,int> map;  
        
        for (auto num : nums) {
            map[num]++;
        }
        vector<int> freq;
        for (auto [k, v] : map) {
            freq.push_back(v);
        }
        int n = freq.size();
        
        vector<int> sum(1<<m);
        for (int i=0; i<(1<<m);i++) {
            for (int j=0;j<m;j++) {
                if (i & (1<<j)) {
                    sum[i] += quantity[j];
                }
            }
        }
        
        vector<vector<int>> dp(((1<<m)), vector<int>(n+1, 0));  
        dp[0][0] = 1;
        
        for (int mask=0;mask<(1<<m);mask++) {
            for (int i=0;i<n;i++) {
                dp[mask][i+1] |= dp[mask][i];    
                
                
                //  Option 1: cur is the old state.  The cornor case is that cur should be able to be 0 and we need a special check to avoid dead loop.
                for (int cur=(mask-1 & mask); cur>=0; cur = (cur-1) & mask) {
                    if (sum[mask] - sum[cur] <= freq[i] && dp[cur][i]) {
                        dp[mask][i+1] = 1;
                    }
                    if (cur==0) break;
                }  
                // Option 2: cur is the change from old state to new state, then given the new state and the change, we need to use XOR operator to get the old state.
                // for (int cur=mask; cur>0; cur= (cur-1)&mask) {
                //     if (sum[cur]<=freq[i] && dp[mask^cur][i]) {
                //         dp[mask][i+1] = 1;
                //     }
                // }
            }
        }
        return dp[(1<<m)-1][n];
    }
};
