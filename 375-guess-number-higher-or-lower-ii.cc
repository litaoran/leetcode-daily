class Solution {
public:
    // range dp
    int getMoneyAmount(int n) {
        if (n<=1) {return 0;}
        vector<vector<int>> dp(n+2, vector<int>(n+2));
        
        for (int len=2;len<=n;len++) {
            for (int i=1;i+len-1<=n;i++) {
                int j = i+len-1;
                if (len==2) {
                    dp[i][j] = i;
                } else {
                    dp[i][j] = INT_MAX;
                    for (int k=i;k<=j;k++) {
                        dp[i][j] = min(dp[i][j], k+max(dp[i][k-1], dp[k+1][j]));
                    }
                    
                }
            }
        }
        return dp[1][n];
        
    }
};
