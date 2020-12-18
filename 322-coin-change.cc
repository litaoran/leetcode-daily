class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount==0) return 0;
        vector<int> dp(amount+1, INT_MAX);
        
        for (auto coin : coins) {
            if (coin<=amount) dp[coin]=1;
        }
        
        for (int i=1;i<=amount;i++) {
            for (auto coin : coins) {
                if (i-coin>=0 && dp[i-coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i-coin]+1);
                }
            }
        }
        return dp[amount]==INT_MAX? -1 : dp[amount]; 
    }
};
