class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> presum(n+1);
        for (int i=1;i<=n;i++) {
            presum[i] = presum[i-1] + piles[i-1];
        }
        
        auto getSum = [&](int s, int e) {
            return presum[e+1] - presum[s];            
        };
        
        vector<vector<int>> dp(n, vector<int>(n));
        for (int len=1;len<=n;len++) {
            for (int i=0;i+len-1<n;i++) {
                int j = i + len - 1;
                
                if (len==1) {dp[i][j]=piles[i];}
                else if (len==2) {
                    dp[i][j]= max(piles[i], piles[j]);
                } else {
                    dp[i][j] = max(piles[i]+getSum(i+1,j)-dp[i+1][j], piles[j]+getSum(i,j-1)-dp[i][j-1]);
                }                
            }    
        }
        return dp[0][n-1]*2 > presum[n];
        
    }
};
