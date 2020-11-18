class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if (m+n != s3.size()) {return false;}
        
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for (int i=1;i<=m;i++) {
            if (dp[i-1][0]) {
                if (s1[i-1] == s3[i-1]) {dp[i][0]=true;}
            } else {
                break;
            }
        }      
        for (int j=1;j<=n;j++) {
            if (dp[0][j-1]) {
                if (s2[j-1] == s3[j-1]) {dp[0][j]=true;}
            } else {
                break;
            }
        }        
    
        for (int i=1;i<=m;i++) {
            for (int j=1;j<=n;j++) {
                if (dp[i-1][j] && s3[i+j-1]==s1[i-1]) dp[i][j]=true;
                if (dp[i][j-1] && s3[i+j-1]==s2[j-1]) dp[i][j]=true;
            }
        }
        return dp[m][n];
    }
};
