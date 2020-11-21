class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        
        for (int i=0;i<n;i++) {dp[i][i]=1;}
        for (int i=0;i+1<n;i++) {
            dp[i][i+1] = (arr[i]==arr[i+1])? 1:2;
        }
    
        
        for (int len=2;len<n;len++) {
            for (int i=0;i+len<n;i++) {
                int j = i+len;
                // Best solution could be either come from 1. remove the cornor symmetric pair  2. current substring divide by 2
                
                if (arr[i] == arr[j]) {
                    dp[i][j] = dp[i+1][j-1];
                } 
                for (int k=i;k<j;k++) {
                     dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
                }
            }
            
        }
        
        
        return dp[0][n-1];
        
    }
};
