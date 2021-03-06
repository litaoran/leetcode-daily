class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n = s.size();
        // dp[i][j]: minimum removed characters to form a palindrome for substring s[i,j].
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for (int len=1;len<=n;len++) {
            for (int i=0;i+len-1<n;i++) {
                int j = i+len-1;  // from i to j
                
                if (len==1) {
                    dp[i][j] = 0;
                } else if (len==2) {
                    if (s[i]==s[j]) {
                        dp[i][j]=0;
                    } else {
                        dp[i][j]=1;
                    }
                } else {
                    if (s[i]==s[j]) {
                        dp[i][j] = dp[i+1][j-1];
                    } else {
                        dp[i][j] = min(dp[i+1][j], dp[i][j-1])+1;
                    }
                }
            }
        }

        return dp[0][n-1]<=k;
    }
};
