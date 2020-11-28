class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        vector<int> suffix_sum(n+1, 0);
        for (int j=n-1;j>=0;j--) {
            suffix_sum[j] = suffix_sum[j+1]+stoneValue[j]; 
        }      
        
        auto getName = [](int val) {
            if (val>0) {
                return "Alice";
            } else if (val<0) {
                return "Bob";
            } else {
                return "Tie";
            }
        };
        
        vector<int> dp(n, INT_MIN);
        dp[n-1] = stoneValue[n-1];
        if (n==1) {
            return getName(dp[n-1]);
        }
        
        dp[n-2] = max(dp[n-2], suffix_sum[n-2]);
        dp[n-2] = max(dp[n-2], suffix_sum[n-2]-dp[n-1]);
        if (n==2) {
            return getName(dp[n-2]*2-suffix_sum[n-2]);
        } 
        
        dp[n-3] = max(dp[n-3], suffix_sum[n-3]);
        dp[n-3] = max(dp[n-3], suffix_sum[n-3]-dp[n-1]);
        dp[n-3] = max(dp[n-3], suffix_sum[n-3]-dp[n-2]);
        if (n==3) {
            return getName(dp[n-3]*2-suffix_sum[n-3]);
        } 
               
        for (int j=n-4;j>=0;j--) {
            dp[j]=max(dp[j], suffix_sum[j]-dp[j+1]);
            dp[j]=max(dp[j], suffix_sum[j]-dp[j+2]);
            dp[j]=max(dp[j], suffix_sum[j]-dp[j+3]);
        }

        
        if (dp[0]*2 > suffix_sum[0]) {
            return "Alice";
        } else if (dp[0]*2 < suffix_sum[0]) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};
