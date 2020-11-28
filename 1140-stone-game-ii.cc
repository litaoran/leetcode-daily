class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int>(n)); // dp[i][j]: when m is j and we have piles starting from idnex i, what's the maximum score we could get.
        
        vector<int> presum(n+1);
        for (int i=1;i<=n;i++) {
            presum[i] +=presum[i-1]+piles[i-1];
        }
        
        auto getSum = [&](int s, int e) {
            return presum[e+1] - presum[s];
        };
        
        for (int j=n-1;j>=0;j--) {
            for (int m=1;m<=n;m++) {
                if (j==n-1) {
                    dp[m][j] = piles[j];
                } else if (j==n-2) {
                    dp[m][j] = piles[j] + piles[j+1];
                } else {
                    int limit = 2*m;
                    int left = n-j;
                    if (left<=limit) {
                        dp[m][j] = getSum(j,n-1);
                    } else {
                        for (int k=1;k<=2*m;k++) {
                            int new_m = max(k,m);
                            if (new_m > n) {new_m = n;}
                            dp[m][j] = max(dp[m][j], getSum(j,n-1) - dp[new_m][j+k]);
                        }
                    }
                }
                
            }
        }

        return dp[1][0];   
    }
};
