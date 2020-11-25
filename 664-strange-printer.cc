class Solution {
public:
    // The key observation is that the end char could always be printed first.
    int strangePrinter(string s) {
        if (s.size() <= 1) return s.size();
        int n = s.size();
        
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        
        for (int i=0;i<n;i++) dp[i][i]=1;
        
        for (int len=2;len<=n;len++) {
            for (int i=0;i+len-1<n;i++) {
                int j = i+len-1;
                if (s[i] == s[j]) {
                    dp[i][j] = min(dp[i+1][j], dp[i][j-1]);
                } 
                for (int k=i;k<j;k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
                }
            }
        }
        
        return dp[0][n-1];    
    }
};
